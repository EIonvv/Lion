
#ifndef LOGGER_H
#define LOGGER_H

#include "../../../modules/module_manager.h"

namespace Logger {
enum class LogLevel { Debug = 0, Info = 1, Warning = 2, Error = 3 };

template <typename T> std::string toString(const T &value) {
  std::ostringstream oss;
  oss << value;
  return oss.str();
}

std::string getCurrentTime();

template <typename T> void log(LogLevel level, const T &message) {
  std::string levelStr;
  std::string colorCode;
  switch (level) {
  case LogLevel::Debug:
    levelStr = "DEBUG";
    colorCode = RESET; // Default color
    break;
  case LogLevel::Info:
    levelStr = "INFO";
    colorCode = GREEN; // Green
    break;
  case LogLevel::Warning:
    levelStr = "WARNING";
    colorCode = YELLOW; // Yellow
    break;
  case LogLevel::Error:
    levelStr = "ERROR";
    colorCode = RED; // Red
    break;
  }
  std::cout << Logger::getCurrentTime() << "[" << colorCode << levelStr << RESET
            << "] " << toString(message) << std::endl;
}

} // namespace Logger
#endif /* LOGGER_H */

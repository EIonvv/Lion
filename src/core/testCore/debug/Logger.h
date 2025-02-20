
#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <sstream>
#include <string>

namespace Logger {
enum class LogLevel { Debug, Info, Warning, Error };

template <typename T> std::string toString(const T &value) {
  std::ostringstream oss;
  oss << value;
  return oss.str();
}

template <typename T> void log(LogLevel level, const T &message) {
  std::string levelStr;
  std::string colorCode;
  switch (level) {
  case LogLevel::Debug:
    levelStr = "DEBUG";
    colorCode = "\033[0m"; // Default color
    break;
  case LogLevel::Info:
    levelStr = "INFO";
    colorCode = "\033[32m"; // Green
    break;
  case LogLevel::Warning:
    levelStr = "WARNING";
    colorCode = "\033[33m"; // Yellow
    break;
  case LogLevel::Error:
    levelStr = "ERROR";
    colorCode = "\033[31m"; // Red
    break;
  }
  std::cout << "[" << colorCode << levelStr << "\033[0m" << "] " << message
            << std::endl;
}

} // namespace Logger
#endif /* LOGGER_H */

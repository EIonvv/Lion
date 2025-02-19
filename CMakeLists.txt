# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Name of the project
project(ModuleTest)

# Check if the system is Linux
if(NOT UNIX)
    message(FATAL_ERROR "This project is only intended to be built on Linux.")
endif()

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add the modules
add_subdirectory(src/modules)

# Add the main executable
add_executable(ModuleTest src/main.cpp)

# Link the libraries to the main executable
target_link_libraries(
    ModuleTest 
    PRIVATE 
    math 
    is_root 
    string 
    username
)

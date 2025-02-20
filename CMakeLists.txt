
# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Name of the project
project(ModuleTest VERSION 1.0.0)

# Check if the system is Linux
if(NOT UNIX)
    message(FATAL_ERROR "This project is only intended to be built on Linux.")
endif()

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable Position-Independent Code (PIC)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Set RPATH for executables
set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

# Add the core
add_subdirectory(src/core)

# Add the modules
add_subdirectory(src/modules)

# Add the main executable
add_executable(${PROJECT_NAME}  src/main.cpp)

# Enable compiler warnings and optimizations
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(${PROJECT_NAME}  PRIVATE
        -Wall        # Enable most warnings
        -Wextra      # Enable extra warnings
        -Wpedantic   # Enforce strict ISO C++ compliance
        -Werror      # Treat warnings as errors (optional)
    )

    # Debug build flags
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_compile_options(${PROJECT_NAME}  PRIVATE
            -g          # Generate debugging information
            -fsanitize=address  # Enable Address Sanitizer
        )
        target_link_options(${PROJECT_NAME}  PRIVATE
            -fsanitize=address  # Enable Address Sanitizer
        )
    endif()

    # Release build flags
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        target_compile_options(${PROJECT_NAME}  PRIVATE
            -O2         # Optimize for performance
            -DNDEBUG    # Disable assertions in release mode
        )
    endif()
endif()

# Linker flags
target_link_options(${PROJECT_NAME}  PRIVATE
    -Wl,--as-needed      # Link only libraries that are actually used
    -Wl,--no-undefined   # Ensure no undefined symbols are present
)

# Link the libraries to the main executable
target_link_libraries(
    ${PROJECT_NAME} 
    PRIVATE 

    # Link the modules
    math 
    is_root 
    username

    # Link the core library
    Core
    Logger
)
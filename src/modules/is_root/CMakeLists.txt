# Create a library for the math module
add_library(is_root root.cpp)

# Make the headers available to other targets
target_include_directories(is_root PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


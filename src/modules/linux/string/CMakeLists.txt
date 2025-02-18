# Create a library for the math module
add_library(string string.cpp)

# Make the headers available to other targets
target_include_directories(string PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


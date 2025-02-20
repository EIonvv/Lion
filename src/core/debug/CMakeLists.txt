# Create a library for the math module
add_library(Logger Logger.cpp)

# Make the headers available to other targets
target_include_directories(Logger PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


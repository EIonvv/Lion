# Create a library for the test_module module
add_library(test_module test_module.cpp)

# Make the headers available to other targets
target_include_directories(test_module PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


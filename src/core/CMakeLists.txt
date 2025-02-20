# Create a library for the math module
add_library(testCore core.cpp)

# Make the headers available to other targets
target_include_directories(testCore PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(debug)

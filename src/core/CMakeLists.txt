# Create a library for the math module
add_library(Core core.cpp)

# Make the headers available to other targets
target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(debug)

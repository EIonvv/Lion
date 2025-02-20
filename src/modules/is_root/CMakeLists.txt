# Create a library for the math module
add_library(is_root root.cpp)

# Make the headers available to other targets
target_include_directories(is_root PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link the math library to the core library
target_link_libraries(is_root PUBLIC Core)
target_link_libraries(is_root PUBLIC Logger)


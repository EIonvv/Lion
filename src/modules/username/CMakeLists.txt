# Create a library for the math module
add_library(username username.cpp)

# Make the headers available to other targets
target_include_directories(username PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link the math library to the core library
target_link_libraries(username PUBLIC Core)


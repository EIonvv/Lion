# Create a library for the math module
add_library(math math.cpp)

# Make the headers available to other targets
target_include_directories(math PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link the math library to the core library
target_link_libraries(math PUBLIC Core) 
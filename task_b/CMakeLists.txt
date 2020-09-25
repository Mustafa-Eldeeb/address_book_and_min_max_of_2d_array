cmake_minimum_required(VERSION 3.10.2)

# set(CMAKE_CXX_STANDARD 17)
project(task_b)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17")




# Find all executables
file(GLOB project_SRCS src/*.cpp) #src/*.h

# Add project executable
add_executable(task_b_main ${project_SRCS})
target_link_libraries(task_b_main )

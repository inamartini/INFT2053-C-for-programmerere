cmake_minimum_required(VERSION 3.27)
project(oving6)

set(CMAKE_CXX_STANDARD 17)

# Find Boost
find_package(Boost 1.70 REQUIRED COMPONENTS system thread)

# Include Boost directories
include_directories(${Boost_INCLUDE_DIRS})

# Link against Boost libraries
add_executable(task_1 task_1.cpp)
add_executable(task_2 task_2.cpp)

target_link_libraries(task_2 ${Boost_LIBRARIES})


cmake_minimum_required(VERSION 3.28)
project(BasicCardGame VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(GameLib)
add_subdirectory(GameLibTests)

set (SOURCE main.cpp)
add_executable(BasicCardGame ${SOURCE})
target_link_libraries(BasicCardGame GameLib)

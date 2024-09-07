cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 20)

set (SOURCE CardTest.cpp)

find_package(GTest REQUIRED)

add_executable(BasicCardGameTest CardTest.cpp)
target_link_libraries(BasicCardGameTest PRIVATE gtest gtest_main GameLib)

cmake_minimum_required(VERSION 3.28)

set(CMAKE_CXX_STANDARD 20)

set (SOURCE CardTest.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(BasicCardGameTest CardTest.cpp)
target_link_libraries(BasicCardGameTest gtest_main GameLib)

enable_testing()

include(GoogleTest)
gtest_discover_tests(BasicCardGameTest)
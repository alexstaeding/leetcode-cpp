cmake_minimum_required(VERSION 3.25)
project(leetcode)
set(CMAKE_CXX_STANDARD 20)
enable_testing()

find_package(Catch2 3 REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_library(leetcode_lib ${SOURCES})
target_include_directories(leetcode_lib PUBLIC inc)

file(GLOB_RECURSE TEST_SOURCES "test/*.cpp")
add_executable(leetcode_tests ${TEST_SOURCES})
target_link_libraries(leetcode_tests leetcode_lib Catch2::Catch2WithMain)
add_test(NAME my_test COMMAND leetcode_tests)

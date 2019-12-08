cmake_minimum_required(VERSION 3.15)

project(Test)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)

set(SOURCES main.cpp ArrayAlgorithmTest.cpp)
add_executable(Test ${SOURCES})
target_link_libraries(Test gtest)

include_directories(../AlgorithmLib)
target_link_libraries(Test AlgorithmLib)
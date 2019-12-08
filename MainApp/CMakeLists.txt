cmake_minimum_required(VERSION 3.15)

project(MainApp)

set(SOURCES main.cpp)

add_executable(MainApp ${SOURCES})

include_directories(../AlgorithmLib)
target_link_libraries(MainApp AlgorithmLib)
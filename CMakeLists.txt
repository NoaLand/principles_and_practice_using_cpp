cmake_minimum_required(VERSION 3.20)
project(principles_and_practice_using_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(chapter2)

add_executable(principles_and_practice_using_cpp
        chapter2/hello_world.cpp
        chapter2/std_lib_facilities.h)

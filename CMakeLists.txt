cmake_minimum_required(VERSION 3.20)
project(principles_and_practice_using_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(chapter2)
include_directories(chapter3)
include_directories(chapter4)
include_directories(chapter5)
include_directories(chapter6)

add_executable(principles_and_practice_using_cpp
#        chapter2/hello_world.cpp
        lib/std_lib_facilities.h
#        chapter3/chapter3.cpp
#        chapter4/chapter4.cpp
#        chapter5/chapter5.cpp
#        chapter6/calculator/calculator.cpp
#        chapter6/calculator/calculator02buggy.cpp
        chapter6/exercise/chapter6.cpp
)

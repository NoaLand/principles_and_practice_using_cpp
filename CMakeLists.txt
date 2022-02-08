cmake_minimum_required(VERSION 3.20)
project(principles_and_practice_using_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(chapter2)
include_directories(chapter3)
include_directories(chapter4)
include_directories(chapter5)
include_directories(chapter6)
include_directories(chapter7)
include_directories(chapter8)

add_executable(principles_and_practice_using_cpp
#        chapter2/hello_world.cpp
        lib/std_lib_facilities.h
#        chapter3/chapter3.cpp
#        chapter4/chapter4.cpp
#        chapter5/chapter5.cpp
#        chapter6/calculator/calculator.cpp
#        chapter6/calculator/calculator02buggy.cpp
#        chapter6/exercise/chapter6.cpp
#        chapter6/english_grammar/english_grammar.cpp
#        chapter7/calculator/calculator.cpp
#        chapter7/calculator/calculator08buggy.cpp
#        chapter8/chapter8.cpp
#        chapter8/simple_exercise1/my.cpp
#        chapter8/simple_exercise1/use.cpp
#        chapter8/simple_exercise2/swap_test.cpp
        chapter8/simple_exercise3/namespace_x_y_and_z.cpp
)

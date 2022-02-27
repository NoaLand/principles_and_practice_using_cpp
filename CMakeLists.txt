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
#        chapter8/simple_exercise3/namespace_x_y_and_z.cpp
#        chapter8/calculator/variable/variable.cpp
#        chapter8/calculator/token/token.cpp
#        chapter8/calculator/calculator.cpp
#        chapter9/date/Chrono.cpp
#        chapter9/date/date_main.cpp
#        chapter9/exercise2_and_3_name_pairs/name_pairs.cpp
#        chapter9/exercise2_and_3_name_pairs/exercise2_and_3.cpp
#        chapter9/exercise4/exercise4.cpp
#        chapter9/exercise5/Book/Book.cpp
#        chapter9/exercise5/exercise5.cpp
#        chapter9/exercise5/Chrono/Chrono.cpp
#        chapter9/exercise13/Rational.cpp
#        chapter9/exercise13/exercise13.cpp
#        chapter9/money/Money.cpp
#        chapter9/money/exercise14_and_15.cpp
#        chapter10/10_5_code_example/Reading.cpp
#        chapter10/10_6_code_example/fill_vector.cpp
        chapter10/10_10_code_example/end_of_loop.cpp
)

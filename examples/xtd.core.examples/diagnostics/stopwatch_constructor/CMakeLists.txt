cmake_minimum_required(VERSION 3.3)

project(stopwatch_constructor)
find_package(xtd REQUIRED)
add_sources(src/stopwatch_constructor.cpp)
target_type(CONSOLE_APPLICATION)

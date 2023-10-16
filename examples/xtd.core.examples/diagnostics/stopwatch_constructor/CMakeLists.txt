cmake_minimum_required(VERSION 3.20)

project(stopwatch_constructor)
find_package(xtd REQUIRED)
add_sources(README.md src/stopwatch_constructor.cpp)
target_type(CONSOLE_APPLICATION)

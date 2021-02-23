cmake_minimum_required(VERSION 3.3)

project(stopwatch)
find_package(xtd REQUIRED)
add_sources(src/stopwatch.cpp)
target_type(CONSOLE_APPLICATION)

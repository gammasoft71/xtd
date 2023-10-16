cmake_minimum_required(VERSION 3.20)

project(stopwatch)
find_package(xtd REQUIRED)
add_sources(README.md src/stopwatch.cpp)
target_type(CONSOLE_APPLICATION)

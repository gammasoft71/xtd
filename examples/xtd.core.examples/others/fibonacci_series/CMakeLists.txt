cmake_minimum_required(VERSION 3.20)

project(fibonacci_series)
find_package(xtd REQUIRED)
add_sources(README.md src/fibonacci_series.cpp)
target_type(CONSOLE_APPLICATION)

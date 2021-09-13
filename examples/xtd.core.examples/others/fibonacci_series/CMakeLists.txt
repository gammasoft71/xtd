cmake_minimum_required(VERSION 3.3)

project(fibonacci_series)
find_package(xtd REQUIRED)
add_sources(src/fibonacci_series.cpp)
target_type(CONSOLE_APPLICATION)

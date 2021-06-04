cmake_minimum_required(VERSION 3.3)

project(test_console)
find_package(xtd REQUIRED)
add_sources(src/test_console.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.20)

project(test_console)
find_package(xtd REQUIRED)
add_sources(README.md src/test_console.cpp)
target_type(CONSOLE_APPLICATION)

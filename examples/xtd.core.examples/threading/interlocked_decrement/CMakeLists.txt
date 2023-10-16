cmake_minimum_required(VERSION 3.20)

project(interlocked_decrement)
find_package(xtd REQUIRED)
add_sources(README.md src/interlocked_decrement.cpp)
target_type(CONSOLE_APPLICATION)

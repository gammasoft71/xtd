cmake_minimum_required(VERSION 3.20)

project(concurrent_stack2)
find_package(xtd REQUIRED)
add_sources(README.md src/concurrent_stack2.cpp)
target_type(CONSOLE_APPLICATION)

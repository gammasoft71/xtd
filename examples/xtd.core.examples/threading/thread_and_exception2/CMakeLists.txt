cmake_minimum_required(VERSION 3.20)

project(thread_and_exception2)
find_package(xtd REQUIRED)
add_sources(README.md src/thread_and_exception2.cpp)
target_type(CONSOLE_APPLICATION)

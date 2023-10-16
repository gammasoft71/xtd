cmake_minimum_required(VERSION 3.20)

project(exception_ptr)
find_package(xtd REQUIRED)
add_sources(README.md src/exception_ptr.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(exception_ptr)
find_package(xtd REQUIRED)
add_sources(src/exception_ptr.cpp)
target_type(CONSOLE_APPLICATION)

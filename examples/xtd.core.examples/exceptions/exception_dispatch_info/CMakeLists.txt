cmake_minimum_required(VERSION 3.20)

project(exception_dispatch_info)
find_package(xtd REQUIRED)
add_sources(README.md src/exception_dispatch_info.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(system_exception)
find_package(xtd REQUIRED)
add_sources(src/system_exception.cpp)
target_type(CONSOLE_APPLICATION)

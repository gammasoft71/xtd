cmake_minimum_required(VERSION 3.5)

project(system_exception)
find_package(xtd REQUIRED)
add_sources(README.md src/system_exception.cpp)
target_type(CONSOLE_APPLICATION)

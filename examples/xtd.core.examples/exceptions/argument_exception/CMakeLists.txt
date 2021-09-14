cmake_minimum_required(VERSION 3.3)

project(argument_exception)
find_package(xtd REQUIRED)
add_sources(src/argument_exception.cpp)
target_type(CONSOLE_APPLICATION)

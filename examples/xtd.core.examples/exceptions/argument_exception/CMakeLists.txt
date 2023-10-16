cmake_minimum_required(VERSION 3.20)

project(argument_exception)
find_package(xtd REQUIRED)
add_sources(README.md src/argument_exception.cpp)
target_type(CONSOLE_APPLICATION)

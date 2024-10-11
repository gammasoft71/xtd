cmake_minimum_required(VERSION 3.20)

project(user_defined_exception)
find_package(xtd REQUIRED)
add_sources(README.md src/user_defined_exception.cpp)
target_type(CONSOLE_APPLICATION)

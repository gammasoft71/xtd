cmake_minimum_required(VERSION 3.20)

project(object)
find_package(xtd REQUIRED)
add_sources(README.md src/object.cpp)
target_type(CONSOLE_APPLICATION)

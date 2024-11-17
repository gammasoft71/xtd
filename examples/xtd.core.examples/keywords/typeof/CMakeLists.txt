cmake_minimum_required(VERSION 3.20)

project(typeof)
find_package(xtd REQUIRED)
add_sources(README.md src/typeof.cpp)
target_type(CONSOLE_APPLICATION)

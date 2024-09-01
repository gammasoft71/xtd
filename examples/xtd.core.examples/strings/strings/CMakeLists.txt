cmake_minimum_required(VERSION 3.20)

project(strings)
find_package(xtd REQUIRED)
add_sources(README.md src/strings.cpp)
target_type(CONSOLE_APPLICATION)

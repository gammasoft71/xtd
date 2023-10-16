cmake_minimum_required(VERSION 3.20)

project(file_info2)
find_package(xtd REQUIRED)
add_sources(README.md src/file_info2.cpp)
target_type(CONSOLE_APPLICATION)

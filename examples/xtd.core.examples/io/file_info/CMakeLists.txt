cmake_minimum_required(VERSION 3.5)

project(file_info)
find_package(xtd REQUIRED)
add_sources(README.md src/file_info.cpp)
target_type(CONSOLE_APPLICATION)

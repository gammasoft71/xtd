cmake_minimum_required(VERSION 3.20)

project(file_info_open)
find_package(xtd REQUIRED)
add_sources(README.md src/file_info_open.cpp)
target_type(CONSOLE_APPLICATION)

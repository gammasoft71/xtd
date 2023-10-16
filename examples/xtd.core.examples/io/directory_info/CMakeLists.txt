cmake_minimum_required(VERSION 3.20)

project(directory_info)
find_package(xtd REQUIRED)
add_sources(README.md src/directory_info.cpp)
target_type(CONSOLE_APPLICATION)

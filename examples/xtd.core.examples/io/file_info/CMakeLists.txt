cmake_minimum_required(VERSION 3.3)

project(file_info)
find_package(xtd REQUIRED)
add_sources(src/file_info.cpp)
target_type(CONSOLE_APPLICATION)

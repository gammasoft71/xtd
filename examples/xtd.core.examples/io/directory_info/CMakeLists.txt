cmake_minimum_required(VERSION 3.3)

project(directory_info)
find_package(xtd REQUIRED)
add_sources(src/directory_info.cpp)
target_type(CONSOLE_APPLICATION)

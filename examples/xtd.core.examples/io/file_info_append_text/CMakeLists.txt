cmake_minimum_required(VERSION 3.20)

project(file_info_append_text)
find_package(xtd REQUIRED)
add_sources(README.md src/file_info_append_text.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(css_reader)
find_package(xtd REQUIRED)
add_sources(src/css_reader.cpp)
target_type(CONSOLE_APPLICATION)

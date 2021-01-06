cmake_minimum_required(VERSION 3.3)

project(css_writer)
find_package(xtd REQUIRED)
add_sources(src/css_writer.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(console_read_line)
find_package(xtd REQUIRED)
add_sources(src/console_read_line.cpp)
target_type(CONSOLE_APPLICATION)

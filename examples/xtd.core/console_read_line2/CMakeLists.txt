cmake_minimum_required(VERSION 3.3)

project(console_read_line2)
find_package(xtd REQUIRED)
add_sources(src/console_read_line2.cpp)
target_type(CONSOLE_APPLICATION)

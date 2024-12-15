cmake_minimum_required(VERSION 3.20)

project(format_tm)
find_package(xtd REQUIRED)
add_sources(README.md src/format_tm.cpp)
target_type(CONSOLE_APPLICATION)

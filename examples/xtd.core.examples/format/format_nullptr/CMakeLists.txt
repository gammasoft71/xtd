cmake_minimum_required(VERSION 3.3)

project(format_nullptr)
find_package(xtd REQUIRED)
add_sources(src/format_nullptr.cpp)
target_type(CONSOLE_APPLICATION)

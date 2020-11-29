cmake_minimum_required(VERSION 3.3)

project(string_unicode)
find_package(xtd REQUIRED)
add_sources(src/string_unicode.cpp)
target_type(CONSOLE_APPLICATION)

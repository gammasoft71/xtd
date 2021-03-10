cmake_minimum_required(VERSION 3.3)

project(format_character)
find_package(xtd REQUIRED)
add_sources(src/format_character.cpp)
target_type(CONSOLE_APPLICATION)

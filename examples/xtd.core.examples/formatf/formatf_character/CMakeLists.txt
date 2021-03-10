cmake_minimum_required(VERSION 3.3)

project(formatf_character)
find_package(xtd REQUIRED)
add_sources(src/formatf_character.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(sprintf_character)
find_package(xtd REQUIRED)
add_sources(src/sprintf_character.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.20)

project(sprintf_character)
find_package(xtd REQUIRED)
add_sources(README.md src/sprintf_character.cpp)
target_type(CONSOLE_APPLICATION)

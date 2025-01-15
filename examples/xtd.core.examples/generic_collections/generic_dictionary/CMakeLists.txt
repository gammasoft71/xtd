cmake_minimum_required(VERSION 3.20)

project(generic_dictionary)
find_package(xtd REQUIRED)
add_sources(README.md src/generic_dictionary.cpp)
target_type(CONSOLE_APPLICATION)

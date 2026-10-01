cmake_minimum_required(VERSION 3.20)

project(extentions_enumerable_iterator)
find_package(xtd REQUIRED)
add_sources(README.md src/extentions_enumerable_iterator.cpp)
target_type(CONSOLE_APPLICATION)

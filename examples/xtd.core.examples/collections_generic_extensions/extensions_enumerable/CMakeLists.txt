cmake_minimum_required(VERSION 3.20)

project(extensions_enumerable)
find_package(xtd REQUIRED)
add_sources(README.md src/extensions_enumerable.cpp)
target_type(CONSOLE_APPLICATION)

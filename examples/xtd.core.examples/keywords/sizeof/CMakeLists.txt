cmake_minimum_required(VERSION 3.20)

project(sizeof)
find_package(xtd REQUIRED)
add_sources(README.md src/sizeof.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(enum)
find_package(xtd REQUIRED)
add_sources(README.md src/enum.cpp)
target_type(CONSOLE_APPLICATION)

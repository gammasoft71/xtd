cmake_minimum_required(VERSION 3.20)

project(comparable)
find_package(xtd REQUIRED)
add_sources(README.md src/comparable.cpp)
target_type(CONSOLE_APPLICATION)

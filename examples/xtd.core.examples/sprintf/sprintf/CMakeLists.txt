cmake_minimum_required(VERSION 3.20)

project(sprintf)
find_package(xtd REQUIRED)
add_sources(README.md src/sprintf.cpp)
target_type(CONSOLE_APPLICATION)

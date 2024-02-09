cmake_minimum_required(VERSION 3.20)

project(action3)
find_package(xtd REQUIRED)
add_sources(README.md src/action3.cpp)
target_type(CONSOLE_APPLICATION)

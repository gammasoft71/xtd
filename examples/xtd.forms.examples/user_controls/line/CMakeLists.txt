cmake_minimum_required(VERSION 3.3)

project(line)
find_package(xtd REQUIRED)
add_sources(README.md src/line.cpp)
target_type(GUI_APPLICATION)

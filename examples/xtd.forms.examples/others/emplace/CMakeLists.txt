cmake_minimum_required(VERSION 3.20)

project(emplace)
find_package(xtd REQUIRED)
add_sources(README.md src/emplace.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.20)

project(splitter)
find_package(xtd REQUIRED)
add_sources(README.md src/splitter.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.20)

project(painting)
find_package(xtd REQUIRED)
add_sources(README.md src/painting.cpp)
target_type(GUI_APPLICATION)

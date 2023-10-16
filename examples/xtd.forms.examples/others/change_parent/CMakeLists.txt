cmake_minimum_required(VERSION 3.20)

project(change_parent)
find_package(xtd REQUIRED)
add_sources(README.md src/change_parent.cpp)
target_type(GUI_APPLICATION)

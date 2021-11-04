cmake_minimum_required(VERSION 3.3)

project(change_parent)
find_package(xtd REQUIRED)
add_sources(src/change_parent.cpp)
target_type(GUI_APPLICATION)

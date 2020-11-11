cmake_minimum_required(VERSION 3.3)

project(cursors)
find_package(xtd REQUIRED)
add_sources(src/cursors.cpp)
target_type(GUI_APPLICATION)

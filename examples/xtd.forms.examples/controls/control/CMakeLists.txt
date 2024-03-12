cmake_minimum_required(VERSION 3.20)

project(control)
find_package(xtd REQUIRED)
add_sources(src/control.cpp)
target_type(GUI_APPLICATION)

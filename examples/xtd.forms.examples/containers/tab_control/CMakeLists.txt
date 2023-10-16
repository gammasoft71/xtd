cmake_minimum_required(VERSION 3.20)

project(tab_control)
find_package(xtd REQUIRED)
add_sources(README.md src/tab_control.cpp)
target_type(GUI_APPLICATION)

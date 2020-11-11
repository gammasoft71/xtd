cmake_minimum_required(VERSION 3.3)

project(tab_control)
find_package(xtd.forms REQUIRED)
add_sources(src/tab_control.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(control)
find_package(xtd.forms REQUIRED)
add_sources(src/control.cpp)
target_type(GUI_APPLICATION)

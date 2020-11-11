cmake_minimum_required(VERSION 3.3)

project(demo)
find_package(xtd.forms REQUIRED)
add_sources(src/demo.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.5)

project(graph_control)
find_package(xtd REQUIRED)
add_sources(README.md src/graph_control.cpp)
target_type(GUI_APPLICATION)

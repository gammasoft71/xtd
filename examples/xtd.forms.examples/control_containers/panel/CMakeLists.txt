cmake_minimum_required(VERSION 3.3)

project(panel)
find_package(xtd REQUIRED)
add_sources(src/panel.cpp)
target_type(GUI_APPLICATION)

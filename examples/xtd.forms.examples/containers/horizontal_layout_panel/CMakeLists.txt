cmake_minimum_required(VERSION 3.20)

project(horizontal_layout_panel)
find_package(xtd REQUIRED)
add_sources(README.md src/horizontal_layout_panel.cpp)
target_type(GUI_APPLICATION)

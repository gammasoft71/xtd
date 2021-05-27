cmake_minimum_required(VERSION 3.3)

project(horizontal_layout_panel)
find_package(xtd REQUIRED)
add_sources(src/horizontal_layout_panel.cpp)
target_type(GUI_APPLICATION)

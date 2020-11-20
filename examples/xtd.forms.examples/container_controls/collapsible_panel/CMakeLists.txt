cmake_minimum_required(VERSION 3.3)

project(collapsible_panel)
find_package(xtd REQUIRED)
add_sources(src/collapsible_panel.cpp)
target_type(GUI_APPLICATION)

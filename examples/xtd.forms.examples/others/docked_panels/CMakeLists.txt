cmake_minimum_required(VERSION 3.3)

project(docked_panels)
find_package(xtd REQUIRED)
add_sources(src/docked_panels.cpp)
target_type(GUI_APPLICATION)

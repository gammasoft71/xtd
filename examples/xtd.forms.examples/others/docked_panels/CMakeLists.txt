cmake_minimum_required(VERSION 3.20)

project(docked_panels)
find_package(xtd REQUIRED)
add_sources(README.md src/docked_panels.cpp)
target_type(GUI_APPLICATION)

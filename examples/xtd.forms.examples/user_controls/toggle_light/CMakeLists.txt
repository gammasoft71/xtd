cmake_minimum_required(VERSION 3.3)

project(toggle_light)
find_package(xtd REQUIRED)
add_sources(README.md src/toggle_light.cpp)
target_type(GUI_APPLICATION)

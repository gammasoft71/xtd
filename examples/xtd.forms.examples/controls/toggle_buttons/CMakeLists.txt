cmake_minimum_required(VERSION 3.3)

project(toggle_buttons)
find_package(xtd REQUIRED)
add_sources(src/toggle_buttons.cpp)
target_type(GUI_APPLICATION)

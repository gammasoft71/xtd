cmake_minimum_required(VERSION 3.20)

project(toggle_buttons)
find_package(xtd REQUIRED)
add_sources(README.md src/toggle_buttons.cpp)
target_type(GUI_APPLICATION)

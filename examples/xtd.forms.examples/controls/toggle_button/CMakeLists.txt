cmake_minimum_required(VERSION 3.20)

project(toggle_button)
find_package(xtd REQUIRED)
add_sources(README.md src/toggle_button.cpp)
target_type(GUI_APPLICATION)

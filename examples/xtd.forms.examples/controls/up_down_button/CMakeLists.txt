cmake_minimum_required(VERSION 3.20)

project(up_down_button)
find_package(xtd REQUIRED)
add_sources(README.md src/up_down_button.cpp)
target_type(GUI_APPLICATION)

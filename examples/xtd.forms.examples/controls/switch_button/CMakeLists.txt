cmake_minimum_required(VERSION 3.20)

project(switch_button)
find_package(xtd REQUIRED)
add_sources(README.md src/switch_button.cpp)
target_type(GUI_APPLICATION)

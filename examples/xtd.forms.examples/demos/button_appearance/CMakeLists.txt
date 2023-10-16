cmake_minimum_required(VERSION 3.20)

project(button_appearance)
find_package(xtd REQUIRED)
add_sources(README.md src/button_appearance.cpp)
target_type(GUI_APPLICATION)

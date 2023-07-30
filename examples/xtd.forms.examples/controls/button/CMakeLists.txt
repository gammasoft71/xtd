cmake_minimum_required(VERSION 3.5)

project(button)
find_package(xtd REQUIRED)
add_sources(README.md src/button.cpp)
target_type(GUI_APPLICATION)

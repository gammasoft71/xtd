cmake_minimum_required(VERSION 3.20)

project(button)
find_package(xtd REQUIRED)
add_sources(src/button.cpp)
target_type(GUI_APPLICATION)

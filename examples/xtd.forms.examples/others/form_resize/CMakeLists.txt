cmake_minimum_required(VERSION 3.20)

project(form_resize)
find_package(xtd REQUIRED)
add_sources(README.md src/form_resize.cpp)
target_type(GUI_APPLICATION)

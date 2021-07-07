cmake_minimum_required(VERSION 3.3)

project(form_resize)
find_package(xtd REQUIRED)
add_sources(src/form_resize.cpp)
target_type(GUI_APPLICATION)

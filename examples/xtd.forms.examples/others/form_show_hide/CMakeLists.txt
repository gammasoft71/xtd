cmake_minimum_required(VERSION 3.3)

project(form_show_hide)
find_package(xtd REQUIRED)
add_sources(src/form_show_hide.cpp)
target_type(GUI_APPLICATION)

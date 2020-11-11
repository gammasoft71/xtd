cmake_minimum_required(VERSION 3.3)

project(form_and_main)
find_package(xtd REQUIRED)
add_sources(src/form_and_main.cpp)
target_type(GUI_APPLICATION)

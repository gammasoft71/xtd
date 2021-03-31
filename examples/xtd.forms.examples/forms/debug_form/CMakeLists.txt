cmake_minimum_required(VERSION 3.3)

project(debug_form)
find_package(xtd REQUIRED)
add_sources(src/debug_form.cpp)
target_type(GUI_APPLICATION)

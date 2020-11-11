cmake_minimum_required(VERSION 3.3)

project(move_form)
find_package(xtd REQUIRED)
add_sources(src/move_form.cpp)
target_type(GUI_APPLICATION)

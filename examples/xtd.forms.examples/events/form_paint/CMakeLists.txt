cmake_minimum_required(VERSION 3.20)

project(form_paint)
find_package(xtd REQUIRED)
add_sources(README.md src/form_paint.cpp)
target_type(GUI_APPLICATION)

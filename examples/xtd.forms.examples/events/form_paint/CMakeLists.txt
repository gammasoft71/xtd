cmake_minimum_required(VERSION 3.3)

project(form_paint)
find_package(xtd REQUIRED)
add_sources(src/form_paint.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(form_decoration)
find_package(xtd REQUIRED)
add_sources(src/form_decoration.cpp)
target_type(GUI_APPLICATION)

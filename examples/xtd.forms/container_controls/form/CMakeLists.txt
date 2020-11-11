cmake_minimum_required(VERSION 3.3)

project(form)
find_package(xtd REQUIRED)
add_sources(src/form.cpp)
target_type(GUI_APPLICATION)

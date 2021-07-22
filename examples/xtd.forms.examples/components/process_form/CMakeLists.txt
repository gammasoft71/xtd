cmake_minimum_required(VERSION 3.3)

project(process_form)
find_package(xtd REQUIRED)
add_sources(src/process_form.cpp)
target_type(GUI_APPLICATION)

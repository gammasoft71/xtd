cmake_minimum_required(VERSION 3.20)

project(process_form)
find_package(xtd REQUIRED)
add_sources(README.md src/process_form.cpp)
target_type(GUI_APPLICATION)

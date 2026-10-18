cmake_minimum_required(VERSION 3.20)

project(form_and_tasks)
find_package(xtd REQUIRED)
add_sources(README.md src/form_and_tasks.cpp)
target_type(GUI_APPLICATION)

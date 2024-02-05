cmake_minimum_required(VERSION 3.20)

project(form_custom_event)
find_package(xtd REQUIRED)
add_sources(README.md src/form_custom_event.cpp)
target_type(GUI_APPLICATION)

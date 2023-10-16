cmake_minimum_required(VERSION 3.20)

project(forms_timer)
find_package(xtd REQUIRED)
add_sources(README.md src/forms_timer.cpp)
target_type(GUI_APPLICATION)

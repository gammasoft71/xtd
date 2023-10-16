cmake_minimum_required(VERSION 3.20)

project(control_with_name_operator)
find_package(xtd REQUIRED)
add_sources(README.md src/control_with_name_operator.cpp)
target_type(GUI_APPLICATION)

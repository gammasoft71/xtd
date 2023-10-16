cmake_minimum_required(VERSION 3.20)

project(some_system_controls)
find_package(xtd REQUIRED)
add_sources(README.md src/some_system_controls.cpp)
target_type(GUI_APPLICATION)

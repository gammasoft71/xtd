cmake_minimum_required(VERSION 3.20)

project(panel)
find_package(xtd REQUIRED)
add_sources(README.md src/panel.cpp)
target_type(GUI_APPLICATION)

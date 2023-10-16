cmake_minimum_required(VERSION 3.20)

project(context_menu)
find_package(xtd REQUIRED)
add_sources(README.md src/context_menu.cpp)
target_type(GUI_APPLICATION)

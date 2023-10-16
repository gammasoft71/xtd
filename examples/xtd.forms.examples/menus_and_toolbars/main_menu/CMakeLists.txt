cmake_minimum_required(VERSION 3.20)

project(main_menu)
find_package(xtd REQUIRED)
add_sources(README.md src/main_menu.cpp)
target_type(GUI_APPLICATION)

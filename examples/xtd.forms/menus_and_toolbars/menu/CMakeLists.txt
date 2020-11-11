cmake_minimum_required(VERSION 3.3)

project(menu)
find_package(xtd.forms REQUIRED)
add_sources(src/menu.cpp)
target_type(GUI_APPLICATION)

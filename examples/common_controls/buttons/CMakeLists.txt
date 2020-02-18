cmake_minimum_required(VERSION 3.3)

project(buttons)
find_package(xtd.forms REQUIRED)
add_sources(src/buttons.cpp)
target_type(GUI_APPLICATION)

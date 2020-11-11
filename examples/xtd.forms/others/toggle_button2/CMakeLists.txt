cmake_minimum_required(VERSION 3.3)

project(toggle_button2)
find_package(xtd.forms REQUIRED)
add_sources(src/toggle_button2.cpp)
target_type(GUI_APPLICATION)

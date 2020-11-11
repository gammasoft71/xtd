cmake_minimum_required(VERSION 3.3)

project(up_down_button)
find_package(xtd.forms REQUIRED)
add_sources(src/up_down_button.cpp)
target_type(GUI_APPLICATION)

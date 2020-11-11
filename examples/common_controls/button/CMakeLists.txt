cmake_minimum_required(VERSION 3.3)

project(button)
find_package(xtd.forms REQUIRED)
add_sources(src/button.cpp)
target_type(GUI_APPLICATION)

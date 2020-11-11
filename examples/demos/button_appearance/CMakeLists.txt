cmake_minimum_required(VERSION 3.3)

project(button_appearance)
find_package(xtd.forms REQUIRED)
add_sources(src/button_appearance.cpp)
target_type(GUI_APPLICATION)

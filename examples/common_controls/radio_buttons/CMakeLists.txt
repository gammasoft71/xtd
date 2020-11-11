cmake_minimum_required(VERSION 3.3)

project(radio_buttons)
find_package(xtd.forms REQUIRED)
add_sources(src/radio_buttons.cpp)
target_type(GUI_APPLICATION)

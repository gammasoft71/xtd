cmake_minimum_required(VERSION 3.3)

project(radio_button_renderer)
find_package(xtd.forms REQUIRED)
add_sources(src/radio_button_renderer.cpp)
target_type(GUI_APPLICATION)

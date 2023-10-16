cmake_minimum_required(VERSION 3.20)

project(radio_button_renderer)
find_package(xtd REQUIRED)
add_sources(README.md src/radio_button_renderer.cpp)
target_type(GUI_APPLICATION)

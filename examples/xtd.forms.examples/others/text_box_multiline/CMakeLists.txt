cmake_minimum_required(VERSION 3.20)

project(text_box_multiline)
find_package(xtd REQUIRED)
add_sources(README.md src/text_box_multiline.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.20)

project(numeric_text_box)
find_package(xtd REQUIRED)
add_sources(README.md src/numeric_text_box.cpp)
target_type(GUI_APPLICATION)

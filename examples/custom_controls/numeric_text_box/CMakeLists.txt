cmake_minimum_required(VERSION 3.3)

project(numeric_text_box)
find_package(xtd.forms REQUIRED)
add_sources(src/numeric_text_box.cpp)
target_type(GUI_APPLICATION)

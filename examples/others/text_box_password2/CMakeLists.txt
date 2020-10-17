cmake_minimum_required(VERSION 3.3)

project(text_box_password2)
find_package(xtd.forms REQUIRED)
add_sources(src/text_box_password2.cpp)
target_type(GUI_APPLICATION)

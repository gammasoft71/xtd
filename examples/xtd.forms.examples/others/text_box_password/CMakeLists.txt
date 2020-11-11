cmake_minimum_required(VERSION 3.3)

project(text_box_password)
find_package(xtd REQUIRED)
add_sources(src/text_box_password.cpp)
target_type(GUI_APPLICATION)

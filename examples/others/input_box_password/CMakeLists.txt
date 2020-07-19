cmake_minimum_required(VERSION 3.3)

project(input_box_password)
find_package(xtd.forms REQUIRED)
add_sources(src/input_box_password.cpp)
target_type(GUI_APPLICATION)

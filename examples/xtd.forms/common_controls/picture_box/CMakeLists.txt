cmake_minimum_required(VERSION 3.3)

project(picture_box)
find_package(xtd.forms REQUIRED)
add_sources(src/picture_box.cpp)
target_type(GUI_APPLICATION)

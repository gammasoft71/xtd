cmake_minimum_required(VERSION 3.3)

project(busy_box)
find_package(xtd REQUIRED)
add_sources(busy_box.cpp)
target_type(GUI_APPLICATION)

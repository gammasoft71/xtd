cmake_minimum_required(VERSION 3.20)

project(link_label)
find_package(xtd REQUIRED)
add_sources(src/link_label.cpp)
target_type(GUI_APPLICATION)

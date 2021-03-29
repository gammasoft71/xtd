cmake_minimum_required(VERSION 3.3)

project(about_box)
find_package(xtd REQUIRED)
target_icon(resources/xtd_forms)
add_sources(src/about_box.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(image_list)
find_package(xtd REQUIRED)
add_sources(src/image_list.cpp)
target_type(GUI_APPLICATION)

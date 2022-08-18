cmake_minimum_required(VERSION 3.3)

project(images)
find_package(xtd REQUIRED)
add_sources(src/images.cpp)
target_type(GUI_APPLICATION)

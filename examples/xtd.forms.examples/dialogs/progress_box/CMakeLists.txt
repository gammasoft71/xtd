cmake_minimum_required(VERSION 3.3)

project(progress_box)
find_package(xtd REQUIRED)
add_sources(src/progress_box.cpp)
target_type(GUI_APPLICATION)

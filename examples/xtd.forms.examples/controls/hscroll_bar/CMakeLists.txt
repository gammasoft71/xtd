cmake_minimum_required(VERSION 3.3)

project(hscroll_bar)
find_package(xtd REQUIRED)
add_sources(src/hscroll_bar.cpp)
target_type(GUI_APPLICATION)

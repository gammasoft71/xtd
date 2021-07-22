cmake_minimum_required(VERSION 3.3)

project(vscroll_bar)
find_package(xtd REQUIRED)
add_sources(src/vscroll_bar.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(h_scroll_bar)
find_package(xtd REQUIRED)
add_sources(src/h_scroll_bar.cpp)
target_type(GUI_APPLICATION)

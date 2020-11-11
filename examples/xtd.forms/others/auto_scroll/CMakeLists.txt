cmake_minimum_required(VERSION 3.3)

project(auto_scroll)
find_package(xtd.forms REQUIRED)
add_sources(src/auto_scroll.cpp)
target_type(GUI_APPLICATION)

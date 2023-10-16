cmake_minimum_required(VERSION 3.20)

project(auto_scroll)
find_package(xtd REQUIRED)
add_sources(README.md src/auto_scroll.cpp)
target_type(GUI_APPLICATION)

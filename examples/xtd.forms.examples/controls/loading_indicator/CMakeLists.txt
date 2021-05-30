cmake_minimum_required(VERSION 3.3)

project(loading_indicator)
find_package(xtd REQUIRED)
add_sources(src/loading_indicator.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(enable_debug)
find_package(xtd REQUIRED)
add_sources(src/enable_debug.cpp)
target_type(GUI_APPLICATION)

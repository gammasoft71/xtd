cmake_minimum_required(VERSION 3.20)

project(exception_box)
find_package(xtd REQUIRED)
add_sources(src/exception_box.cpp)
target_type(GUI_APPLICATION)

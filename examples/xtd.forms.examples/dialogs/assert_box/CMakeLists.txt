cmake_minimum_required(VERSION 3.5)

project(assert_box)
find_package(xtd REQUIRED)
add_sources(README.md src/assert_box.cpp)
target_type(GUI_APPLICATION)

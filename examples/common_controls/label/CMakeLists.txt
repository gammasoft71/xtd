cmake_minimum_required(VERSION 3.3)

project(label)
find_package(xtd.forms REQUIRED)
add_sources(src/label.cpp)
target_type(GUI_APPLICATION)

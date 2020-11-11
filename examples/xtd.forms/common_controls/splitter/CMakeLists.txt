cmake_minimum_required(VERSION 3.3)

project(splitter)
find_package(xtd.forms REQUIRED)
add_sources(src/splitter.cpp)
target_type(GUI_APPLICATION)

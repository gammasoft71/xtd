cmake_minimum_required(VERSION 3.3)

project(split_container)
find_package(xtd.forms REQUIRED)
add_sources(src/split_container.cpp)
target_type(GUI_APPLICATION)

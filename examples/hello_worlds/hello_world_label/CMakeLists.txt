cmake_minimum_required(VERSION 3.3)

project(hello_world_label)
find_package(xtd.forms REQUIRED)
add_sources(src/hello_world_label.cpp)
target_type(GUI_APPLICATION)

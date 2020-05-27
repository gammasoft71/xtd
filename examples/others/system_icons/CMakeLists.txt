cmake_minimum_required(VERSION 3.3)

project(system_icons)
find_package(xtd.forms REQUIRED)
add_sources(src/system_icons.cpp)
target_type(GUI_APPLICATION)

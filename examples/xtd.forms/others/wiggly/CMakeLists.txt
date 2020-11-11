cmake_minimum_required(VERSION 3.3)

project(wiggly)
find_package(xtd.forms REQUIRED)
add_sources(src/wiggly.cpp)
target_type(GUI_APPLICATION)

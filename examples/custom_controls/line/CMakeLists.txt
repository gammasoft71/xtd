cmake_minimum_required(VERSION 3.3)

project(line)
find_package(xtd.forms REQUIRED)
add_sources(src/line.cpp)
target_type(GUI_APPLICATION)

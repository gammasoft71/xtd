cmake_minimum_required(VERSION 3.3)

project(button4)
find_package(xtd.forms REQUIRED)
add_sources(src/button4.cpp)
target_type(GUI_APPLICATION)

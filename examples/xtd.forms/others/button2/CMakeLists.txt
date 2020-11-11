cmake_minimum_required(VERSION 3.3)

project(button2)
find_package(xtd REQUIRED)
add_sources(src/button2.cpp)
target_type(GUI_APPLICATION)

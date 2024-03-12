cmake_minimum_required(VERSION 3.20)

project(animation)
find_package(xtd REQUIRED)
add_sources(src/animation.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(timer)
find_package(xtd REQUIRED)
add_sources(src/timer.cpp)
target_type(GUI_APPLICATION)

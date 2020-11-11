cmake_minimum_required(VERSION 3.3)

project(clock)
find_package(xtd REQUIRED)
add_sources(src/clock.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(screen)
find_package(xtd REQUIRED)
add_sources(src/screen.cpp)
target_type(GUI_APPLICATION)

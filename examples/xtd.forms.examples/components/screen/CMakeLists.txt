cmake_minimum_required(VERSION 3.20)

project(screen)
find_package(xtd REQUIRED)
add_sources(README.md src/screen.cpp)
target_type(GUI_APPLICATION)

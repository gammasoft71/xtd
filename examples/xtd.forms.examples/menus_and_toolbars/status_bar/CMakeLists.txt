cmake_minimum_required(VERSION 3.20)

project(status_bar)
find_package(xtd REQUIRED)
add_sources(README.md src/status_bar.cpp)
target_type(GUI_APPLICATION)

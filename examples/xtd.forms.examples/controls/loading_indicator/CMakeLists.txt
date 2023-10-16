cmake_minimum_required(VERSION 3.20)

project(loading_indicator)
find_package(xtd REQUIRED)
add_sources(README.md src/loading_indicator.cpp)
target_type(GUI_APPLICATION)

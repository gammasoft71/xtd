cmake_minimum_required(VERSION 3.20)

project(loading_indicators)
find_package(xtd REQUIRED)
add_sources(README.md src/loading_indicators.cpp)
target_type(GUI_APPLICATION)

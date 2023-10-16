cmake_minimum_required(VERSION 3.20)

project(label)
find_package(xtd REQUIRED)
add_sources(README.md src/label.cpp)
target_type(GUI_APPLICATION)

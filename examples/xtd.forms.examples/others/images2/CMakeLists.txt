cmake_minimum_required(VERSION 3.20)

project(images2)
find_package(xtd REQUIRED)
add_sources(README.md src/images2.cpp)
target_type(GUI_APPLICATION)

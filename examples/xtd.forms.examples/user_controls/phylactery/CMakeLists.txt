cmake_minimum_required(VERSION 3.20)

project(phylactery)
find_package(xtd REQUIRED)
add_sources(README.md src/phylactery.cpp)
target_type(GUI_APPLICATION)

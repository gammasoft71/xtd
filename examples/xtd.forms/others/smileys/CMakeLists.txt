cmake_minimum_required(VERSION 3.3)

project(smileys)
find_package(xtd REQUIRED)
add_sources(src/smileys.cpp)
target_type(GUI_APPLICATION)

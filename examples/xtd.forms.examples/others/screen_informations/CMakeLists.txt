cmake_minimum_required(VERSION 3.3)

project(screen_informations)
find_package(xtd REQUIRED)
add_references(xtd)
add_sources(src/screen_informations.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.20)

project(screen_informations)
find_package(xtd REQUIRED)
add_sources(README.md src/screen_informations.cpp)
target_type(GUI_APPLICATION)

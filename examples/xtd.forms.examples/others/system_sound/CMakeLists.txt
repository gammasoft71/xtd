cmake_minimum_required(VERSION 3.20)

project(system_sound)
find_package(xtd REQUIRED)
add_sources(README.md src/system_sound.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(system_sound)
find_package(xtd REQUIRED)
add_sources(src/system_sound.cpp)
target_type(GUI_APPLICATION)

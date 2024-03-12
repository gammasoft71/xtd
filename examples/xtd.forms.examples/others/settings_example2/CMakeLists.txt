cmake_minimum_required(VERSION 3.20)

project(settings_example2)
find_package(xtd REQUIRED)
add_sources(src/settings_example2.cpp)
target_type(GUI_APPLICATION)

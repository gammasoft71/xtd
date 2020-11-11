cmake_minimum_required(VERSION 3.3)

project(settings_example2)
find_package(xtd.forms REQUIRED)
add_sources(src/settings_example2.cpp)
target_type(GUI_APPLICATION)

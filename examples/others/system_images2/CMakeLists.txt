cmake_minimum_required(VERSION 3.3)

project(system_images2)
find_package(xtd.forms REQUIRED)
add_sources(src/system_images2.cpp)
target_type(GUI_APPLICATION)

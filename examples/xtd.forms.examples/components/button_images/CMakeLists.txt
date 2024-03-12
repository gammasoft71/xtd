cmake_minimum_required(VERSION 3.20)

project(button_images)
find_package(xtd REQUIRED)
add_sources(src/button_images.cpp)
target_type(GUI_APPLICATION)

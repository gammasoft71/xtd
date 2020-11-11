cmake_minimum_required(VERSION 3.3)

project(button_images)
find_package(xtd.forms REQUIRED)
add_sources(src/button_images.cpp)
target_type(GUI_APPLICATION)

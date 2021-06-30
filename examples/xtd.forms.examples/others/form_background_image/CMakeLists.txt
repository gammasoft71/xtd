cmake_minimum_required(VERSION 3.3)

project(form_background_image)
find_package(xtd REQUIRED)
add_sources(src/form_background_image.cpp)
target_type(GUI_APPLICATION)

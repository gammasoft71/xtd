cmake_minimum_required(VERSION 3.3)

project(form_show)
find_package(xtd.forms REQUIRED)
add_sources(src/form_show.cpp)
target_type(GUI_APPLICATION)

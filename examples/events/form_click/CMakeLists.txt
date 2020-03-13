cmake_minimum_required(VERSION 3.3)

project(form_click)
find_package(xtd.forms REQUIRED)
add_sources(src/form_click.cpp)
target_type(GUI_APPLICATION)

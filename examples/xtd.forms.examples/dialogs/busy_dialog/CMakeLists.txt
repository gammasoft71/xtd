cmake_minimum_required(VERSION 3.20)

project(busy_dialog)
find_package(xtd REQUIRED)
add_sources(busy_dialog.cpp)
target_type(GUI_APPLICATION)

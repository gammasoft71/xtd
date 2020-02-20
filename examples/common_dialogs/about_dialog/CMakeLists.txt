cmake_minimum_required(VERSION 3.3)

project(about_dialog)
find_package(xtd.forms REQUIRED)
add_sources(src/about_dialog.cpp)
target_type(GUI_APPLICATION)

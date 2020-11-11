cmake_minimum_required(VERSION 3.3)

project(busy_dialog)
find_package(xtd.forms REQUIRED)
add_sources(busy_dialog.cpp)
target_type(GUI_APPLICATION)

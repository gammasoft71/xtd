cmake_minimum_required(VERSION 3.3)

project(progress_dialog)
find_package(xtd.forms REQUIRED)
add_sources(progress_dialog.cpp)
target_type(GUI_APPLICATION)

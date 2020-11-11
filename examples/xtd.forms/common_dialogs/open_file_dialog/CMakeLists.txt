cmake_minimum_required(VERSION 3.3)

project(open_file_dialog)
find_package(xtd.forms REQUIRED)
add_sources(src/open_file_dialog.cpp)
target_type(GUI_APPLICATION)

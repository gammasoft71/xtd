cmake_minimum_required(VERSION 3.3)

project(folder_browser_dialog)
find_package(xtd REQUIRED)
add_sources(src/folder_browser_dialog.cpp)
target_type(GUI_APPLICATION)

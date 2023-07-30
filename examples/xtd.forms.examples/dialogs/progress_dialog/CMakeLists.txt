cmake_minimum_required(VERSION 3.5)

project(progress_dialog)
find_package(xtd REQUIRED)
add_sources(README.md src/progress_dialog.cpp)
target_type(GUI_APPLICATION)

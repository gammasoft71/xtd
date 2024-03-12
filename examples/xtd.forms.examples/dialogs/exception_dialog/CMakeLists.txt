cmake_minimum_required(VERSION 3.20)

project(exception_dialog)
find_package(xtd REQUIRED)
add_sources(src/exception_dialog.cpp)
target_type(GUI_APPLICATION)

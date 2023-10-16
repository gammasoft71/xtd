cmake_minimum_required(VERSION 3.20)

project(button_with_style_sheet)
find_package(xtd REQUIRED)
add_sources(README.md src/button_with_style_sheet.cpp)
target_type(GUI_APPLICATION)

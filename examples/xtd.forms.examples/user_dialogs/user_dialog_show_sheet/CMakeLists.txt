cmake_minimum_required(VERSION 3.20)

project(user_dialog_show_sheet)
find_package(xtd REQUIRED)
add_sources(README.md src/user_dialog_show_sheet.cpp)
target_type(GUI_APPLICATION)

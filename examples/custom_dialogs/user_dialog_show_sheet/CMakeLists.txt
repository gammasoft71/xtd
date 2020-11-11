cmake_minimum_required(VERSION 3.3)

project(user_dialog_show_sheet)
find_package(xtd.forms REQUIRED)
add_sources(src/user_dialog_show_sheet.cpp)
target_type(GUI_APPLICATION)

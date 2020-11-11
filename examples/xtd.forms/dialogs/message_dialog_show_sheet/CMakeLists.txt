cmake_minimum_required(VERSION 3.3)

project(message_dialog_show_sheet)
find_package(xtd.forms REQUIRED)
add_sources(src/message_dialog_show_sheet.cpp)
target_type(GUI_APPLICATION)

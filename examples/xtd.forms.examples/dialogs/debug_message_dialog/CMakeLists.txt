cmake_minimum_required(VERSION 3.20)

project(debug_message_dialog)
find_package(xtd REQUIRED)
add_sources(README.md src/debug_message_dialog.cpp)
target_type(GUI_APPLICATION)

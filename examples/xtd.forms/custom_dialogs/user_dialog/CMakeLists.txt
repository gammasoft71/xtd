cmake_minimum_required(VERSION 3.3)

project(user_dialog)
find_package(xtd REQUIRED)
add_sources(src/user_dialog.cpp)
target_type(GUI_APPLICATION)

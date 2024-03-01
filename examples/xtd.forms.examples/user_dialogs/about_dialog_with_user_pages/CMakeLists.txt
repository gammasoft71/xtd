cmake_minimum_required(VERSION 3.20)

project(about_dialog_with_user_pages)
find_package(xtd REQUIRED)
add_sources(README.md src/about_dialog_with_user_pages.cpp)
target_type(GUI_APPLICATION)

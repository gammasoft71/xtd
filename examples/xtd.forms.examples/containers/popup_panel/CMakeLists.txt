cmake_minimum_required(VERSION 3.20)

project(popup_panel)
find_package(xtd REQUIRED)
add_sources(README.md src/popup_panel.cpp)
target_type(GUI_APPLICATION)

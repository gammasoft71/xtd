cmake_minimum_required(VERSION 3.20)

project(lcd_label3)
find_package(xtd REQUIRED)
add_sources(README.md src/lcd_label3.cpp)
target_type(GUI_APPLICATION)

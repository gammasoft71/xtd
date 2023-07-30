cmake_minimum_required(VERSION 3.5)

project(lcd_label)
find_package(xtd REQUIRED)
add_sources(README.md src/lcd_label.cpp)
target_type(GUI_APPLICATION)

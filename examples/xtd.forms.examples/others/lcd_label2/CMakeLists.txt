cmake_minimum_required(VERSION 3.20)

project(lcd_label2)
find_package(xtd REQUIRED)
add_sources(README.md src/lcd_label2.cpp)
target_type(GUI_APPLICATION)

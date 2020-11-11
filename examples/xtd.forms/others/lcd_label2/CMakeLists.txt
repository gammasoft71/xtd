cmake_minimum_required(VERSION 3.3)

project(lcd_label2)
find_package(xtd REQUIRED)
add_sources(src/lcd_label2.cpp)
target_type(GUI_APPLICATION)

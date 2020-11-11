cmake_minimum_required(VERSION 3.3)

project(lcd_label_appearance)
find_package(xtd REQUIRED)
add_sources(src/lcd_label_appearance.cpp)
target_type(GUI_APPLICATION)

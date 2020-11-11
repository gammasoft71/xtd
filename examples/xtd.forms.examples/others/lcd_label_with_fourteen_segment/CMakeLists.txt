cmake_minimum_required(VERSION 3.3)

project(lcd_label_with_fourteen_segment)
find_package(xtd REQUIRED)
add_sources(src/lcd_label_with_fourteen_segment.cpp)
target_type(GUI_APPLICATION)

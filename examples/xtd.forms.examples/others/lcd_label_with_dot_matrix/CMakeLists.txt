cmake_minimum_required(VERSION 3.20)

project(lcd_label_with_dot_matrix)
find_package(xtd REQUIRED)
add_sources(README.md src/lcd_label_with_dot_matrix.cpp)
target_type(GUI_APPLICATION)

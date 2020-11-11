cmake_minimum_required(VERSION 3.3)

project(lcd_label_with_dot_matrix)
find_package(xtd.forms REQUIRED)
add_sources(src/lcd_label_with_dot_matrix.cpp)
target_type(GUI_APPLICATION)

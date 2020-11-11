cmake_minimum_required(VERSION 3.3)

project(lcd_label)
find_package(xtd.forms REQUIRED)
add_sources(src/lcd_label.cpp)
target_type(GUI_APPLICATION)

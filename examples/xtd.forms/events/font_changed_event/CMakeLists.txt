cmake_minimum_required(VERSION 3.3)

project(font_changed_event)
find_package(xtd.forms REQUIRED)
add_sources(src/font_changed_event.cpp)
target_type(GUI_APPLICATION)

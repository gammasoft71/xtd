cmake_minimum_required(VERSION 3.3)

project(enable_changed_event)
find_package(xtd REQUIRED)
add_sources(src/enable_changed_event.cpp)
target_type(GUI_APPLICATION)

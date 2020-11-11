cmake_minimum_required(VERSION 3.3)

project(date_time_picker)
find_package(xtd REQUIRED)
add_sources(src/date_time_picker.cpp)
target_type(GUI_APPLICATION)

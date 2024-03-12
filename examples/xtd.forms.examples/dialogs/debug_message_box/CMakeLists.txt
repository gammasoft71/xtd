cmake_minimum_required(VERSION 3.20)

project(debug_message_box)
find_package(xtd REQUIRED)
add_sources(src/debug_message_box.cpp)
target_type(GUI_APPLICATION)

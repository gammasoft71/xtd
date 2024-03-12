cmake_minimum_required(VERSION 3.20)

project(trace_message_box)
find_package(xtd REQUIRED)
add_sources(src/trace_message_box.cpp)
target_type(GUI_APPLICATION)

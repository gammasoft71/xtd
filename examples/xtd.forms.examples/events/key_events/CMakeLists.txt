cmake_minimum_required(VERSION 3.20)

project(key_events)
find_package(xtd REQUIRED)
add_sources(src/key_events.cpp)
target_type(GUI_APPLICATION)

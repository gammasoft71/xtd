cmake_minimum_required(VERSION 3.5)

project(mouse_events)
find_package(xtd REQUIRED)
add_sources(README.md src/mouse_events.cpp)
target_type(GUI_APPLICATION)

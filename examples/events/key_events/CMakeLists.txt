cmake_minimum_required(VERSION 3.3)

project(key_events)
find_package(xtd.forms REQUIRED)
add_sources(src/key_events.cpp)
target_type(GUI_APPLICATION)

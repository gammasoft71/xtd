cmake_minimum_required(VERSION 3.3)

project(track_bar2)
find_package(xtd.forms REQUIRED)
add_sources(src/track_bar2.cpp)
target_type(GUI_APPLICATION)

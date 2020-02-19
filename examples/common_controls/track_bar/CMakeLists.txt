cmake_minimum_required(VERSION 3.3)

project(track_bar)
find_package(xtd.forms REQUIRED)
add_sources(src/track_bar.cpp)
target_type(GUI_APPLICATION)

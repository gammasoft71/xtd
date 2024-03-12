cmake_minimum_required(VERSION 3.20)

project(track_bar)
find_package(xtd REQUIRED)
add_sources(src/track_bar.cpp)
target_type(GUI_APPLICATION)

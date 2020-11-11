cmake_minimum_required(VERSION 3.3)

project(wnd_proc)
find_package(xtd REQUIRED)
add_sources(src/wnd_proc.cpp)
target_type(GUI_APPLICATION)

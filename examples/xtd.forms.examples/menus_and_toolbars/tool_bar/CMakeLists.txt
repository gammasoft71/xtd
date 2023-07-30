cmake_minimum_required(VERSION 3.5)

project(tool_bar)
find_package(xtd REQUIRED)
add_sources(README.md src/tool_bar.cpp)
target_type(GUI_APPLICATION)

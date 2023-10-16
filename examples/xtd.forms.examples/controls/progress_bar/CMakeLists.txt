cmake_minimum_required(VERSION 3.20)

project(progress_bar)
find_package(xtd REQUIRED)
add_sources(README.md src/progress_bar.cpp)
target_type(GUI_APPLICATION)

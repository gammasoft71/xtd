cmake_minimum_required(VERSION 3.5)

project(use_wait_cursor)
find_package(xtd REQUIRED)
add_sources(README.md src/use_wait_cursor.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(cursor)
find_package(xtd.forms REQUIRED)
add_sources(src/cursor.cpp)
target_type(GUI_APPLICATION)

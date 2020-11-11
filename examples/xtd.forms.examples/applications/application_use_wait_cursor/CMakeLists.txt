cmake_minimum_required(VERSION 3.3)

project(application_use_wait_cursor)
find_package(xtd REQUIRED)
add_sources(src/application_use_wait_cursor.cpp)
target_type(GUI_APPLICATION)

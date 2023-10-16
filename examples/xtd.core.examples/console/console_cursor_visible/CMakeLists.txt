cmake_minimum_required(VERSION 3.20)

project(console_cursor_visible)
find_package(xtd REQUIRED)
add_sources(README.md src/console_cursor_visible.cpp)
target_type(CONSOLE_APPLICATION)

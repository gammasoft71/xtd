cmake_minimum_required(VERSION 3.3)

project(console_cursor)
find_package(xtd REQUIRED)
add_sources(src/console_cursor.cpp)
target_type(CONSOLE_APPLICATION)

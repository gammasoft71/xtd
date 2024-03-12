cmake_minimum_required(VERSION 3.20)

project(console_cursor)
find_package(xtd REQUIRED)
add_sources(src/console_cursor.cpp)
target_type(CONSOLE_APPLICATION)

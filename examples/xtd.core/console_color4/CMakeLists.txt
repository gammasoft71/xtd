cmake_minimum_required(VERSION 3.3)

project(console_color4)
find_package(xtd REQUIRED)
add_sources(src/console_color4.cpp)
target_type(CONSOLE_APPLICATION)

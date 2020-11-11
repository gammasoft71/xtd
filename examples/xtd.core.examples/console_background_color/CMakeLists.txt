cmake_minimum_required(VERSION 3.3)

project(console_background_color)
find_package(xtd REQUIRED)
add_sources(src/console_background_color.cpp)
target_type(CONSOLE_APPLICATION)

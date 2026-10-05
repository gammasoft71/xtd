cmake_minimum_required(VERSION 3.20)

project(graphics_draw_line)
find_package(xtd REQUIRED)
add_sources(README.md src/graphics_draw_line.cpp)
target_type(CONSOLE_APPLICATION)

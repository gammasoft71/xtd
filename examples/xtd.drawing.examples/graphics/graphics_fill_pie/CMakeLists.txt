cmake_minimum_required(VERSION 3.20)

project(graphics_fill_pie)
find_package(xtd REQUIRED)
add_sources(README.md src/graphics_fill_pie.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.20)

project(graphics_draw_ellipse)
find_package(xtd REQUIRED)
add_sources(README.md src/graphics_draw_ellipse.cpp)
target_type(CONSOLE_APPLICATION)

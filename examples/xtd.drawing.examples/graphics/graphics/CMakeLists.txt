cmake_minimum_required(VERSION 3.20)

project(graphics)
find_package(xtd REQUIRED)
add_sources(README.md src/graphics.cpp)
target_type(CONSOLE_APPLICATION)

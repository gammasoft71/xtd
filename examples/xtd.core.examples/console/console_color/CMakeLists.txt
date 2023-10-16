cmake_minimum_required(VERSION 3.20)

project(console_color)
find_package(xtd REQUIRED)
add_sources(README.md src/console_color.cpp)
target_type(CONSOLE_APPLICATION)

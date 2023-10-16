cmake_minimum_required(VERSION 3.20)

project(console_background_color)
find_package(xtd REQUIRED)
add_sources(README.md src/console_background_color.cpp)
target_type(CONSOLE_APPLICATION)

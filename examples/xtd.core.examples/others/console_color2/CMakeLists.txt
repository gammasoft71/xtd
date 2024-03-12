cmake_minimum_required(VERSION 3.20)

project(console_color2)
find_package(xtd REQUIRED)
add_sources(src/console_color2.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(console_title)
find_package(xtd REQUIRED)
add_sources(src/console_title.cpp)
target_type(CONSOLE_APPLICATION)

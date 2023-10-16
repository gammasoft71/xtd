cmake_minimum_required(VERSION 3.20)

project(console_title)
find_package(xtd REQUIRED)
add_sources(README.md src/console_title.cpp)
target_type(CONSOLE_APPLICATION)

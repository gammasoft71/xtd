cmake_minimum_required(VERSION 3.3)

project(console_window_size)
find_package(xtd REQUIRED)
add_sources(README.md src/console_window_size.cpp)
target_type(CONSOLE_APPLICATION)

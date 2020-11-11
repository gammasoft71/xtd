cmake_minimum_required(VERSION 3.3)

project(tutorial_console_write_line)
find_package(xtd.console REQUIRED)
add_sources(src/console_write_line.cpp)
target_type(CONSOLE_APPLICATION)

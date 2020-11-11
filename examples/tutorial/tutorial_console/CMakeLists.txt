cmake_minimum_required(VERSION 3.3)

project(tutorial_console)
find_package(xtd.console REQUIRED)
add_sources(src/console.cpp)
target_type(CONSOLE_APPLICATION)

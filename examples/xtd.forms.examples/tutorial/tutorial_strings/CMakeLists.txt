cmake_minimum_required(VERSION 3.20)

project(tutorial_strings)
find_package(xtd.console REQUIRED)
add_sources(src/strings.cpp)
target_type(CONSOLE_APPLICATION)

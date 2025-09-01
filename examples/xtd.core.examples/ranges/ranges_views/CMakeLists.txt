cmake_minimum_required(VERSION 3.20)

project(ranges_views)
find_package(xtd REQUIRED)
add_sources(README.md src/ranges_views.cpp)
target_type(CONSOLE_APPLICATION)

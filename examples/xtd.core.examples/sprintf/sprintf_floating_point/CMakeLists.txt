cmake_minimum_required(VERSION 3.3)

project(sprintf_floating_point)
find_package(xtd REQUIRED)
add_sources(src/sprintf_floating_point.cpp)
target_type(CONSOLE_APPLICATION)

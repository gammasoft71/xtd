cmake_minimum_required(VERSION 3.20)

project(sprintf_floating_point)
find_package(xtd REQUIRED)
add_sources(README.md src/sprintf_floating_point.cpp)
target_type(CONSOLE_APPLICATION)

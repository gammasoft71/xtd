cmake_minimum_required(VERSION 3.3)

project(formatf_floating_point)
find_package(xtd REQUIRED)
add_sources(src/formatf_floating_point.cpp)
target_type(CONSOLE_APPLICATION)

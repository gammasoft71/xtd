cmake_minimum_required(VERSION 3.3)

project(formatf)
find_package(xtd REQUIRED)
add_sources(src/formatf.cpp)
target_type(CONSOLE_APPLICATION)

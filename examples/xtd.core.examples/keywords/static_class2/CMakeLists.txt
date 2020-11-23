cmake_minimum_required(VERSION 3.3)

project(static_class2)
find_package(xtd REQUIRED)
add_sources(src/static_class2.cpp)
target_type(CONSOLE_APPLICATION)

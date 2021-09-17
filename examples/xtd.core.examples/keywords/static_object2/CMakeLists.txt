cmake_minimum_required(VERSION 3.3)

project(static_object2)
find_package(xtd REQUIRED)
add_sources(src/static_object2.cpp)
target_type(CONSOLE_APPLICATION)

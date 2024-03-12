cmake_minimum_required(VERSION 3.20)

project(static_object)
find_package(xtd REQUIRED)
add_sources(src/static_object.cpp)
target_type(CONSOLE_APPLICATION)

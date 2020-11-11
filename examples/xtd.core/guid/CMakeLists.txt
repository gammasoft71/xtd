cmake_minimum_required(VERSION 3.3)

project(guid)
find_package(xtd REQUIRED)
add_sources(src/guid.cpp)
target_type(CONSOLE_APPLICATION)

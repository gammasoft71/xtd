cmake_minimum_required(VERSION 3.20)

project(guid)
find_package(xtd REQUIRED)
add_sources(src/guid.cpp)
target_type(CONSOLE_APPLICATION)

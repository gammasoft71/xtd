cmake_minimum_required(VERSION 3.3)

project(formatf_boolean)
find_package(xtd REQUIRED)
add_sources(src/formatf_boolean.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(formatf_class)
find_package(xtd REQUIRED)
add_sources(src/formatf_class.cpp)
target_type(CONSOLE_APPLICATION)

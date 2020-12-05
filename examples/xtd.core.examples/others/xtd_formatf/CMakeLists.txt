cmake_minimum_required(VERSION 3.3)

project(xtd_formatf)
find_package(xtd REQUIRED)
add_sources(src/xtd_formatf.cpp)
target_type(CONSOLE_APPLICATION)

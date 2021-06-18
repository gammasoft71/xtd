cmake_minimum_required(VERSION 3.3)

project(csf)
find_package(xtd REQUIRED)
add_sources(src/csf.cpp)
target_type(CONSOLE_APPLICATION)

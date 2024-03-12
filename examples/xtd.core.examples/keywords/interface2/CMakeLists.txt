cmake_minimum_required(VERSION 3.20)

project(interface2)
find_package(xtd REQUIRED)
add_sources(src/interface2.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(interface2)
find_package(xtd REQUIRED)
add_sources(interface2.cpp)
target_type(CONSOLE_APPLICATION)

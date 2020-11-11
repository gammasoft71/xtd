cmake_minimum_required(VERSION 3.3)

project(static2)
find_package(xtd REQUIRED)
add_sources(static2.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(static3)
find_package(xtd.core REQUIRED)
find_package(xtd REQUIRED)
add_sources(static3.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(main)
find_package(xtd REQUIRED)
add_sources(src/main.cpp)
target_type(CONSOLE_APPLICATION)

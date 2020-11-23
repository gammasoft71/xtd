cmake_minimum_required(VERSION 3.3)

project(main3)
find_package(xtd REQUIRED)
add_sources(src/main3.cpp)
target_type(CONSOLE_APPLICATION)

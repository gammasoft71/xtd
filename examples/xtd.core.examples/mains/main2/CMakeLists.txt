cmake_minimum_required(VERSION 3.3)

project(main2)
find_package(xtd REQUIRED)
add_sources(src/main2.cpp)
target_type(CONSOLE_APPLICATION)

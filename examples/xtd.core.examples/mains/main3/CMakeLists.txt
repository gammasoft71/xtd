cmake_minimum_required(VERSION 3.20)

project(main3)
find_package(xtd REQUIRED)
add_sources(README.md src/main3.cpp)
target_type(CONSOLE_APPLICATION)

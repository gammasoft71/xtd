cmake_minimum_required(VERSION 3.20)

project(main)
find_package(xtd REQUIRED)
add_sources(README.md src/main.cpp)
target_type(CONSOLE_APPLICATION)

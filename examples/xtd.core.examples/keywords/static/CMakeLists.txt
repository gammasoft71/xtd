cmake_minimum_required(VERSION 3.20)

project(static)
find_package(xtd REQUIRED)
add_sources(README.md src/static.cpp)
target_type(CONSOLE_APPLICATION)

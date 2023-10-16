cmake_minimum_required(VERSION 3.20)

project(random1)
find_package(xtd REQUIRED)
add_sources(README.md src/random1.cpp)
target_type(CONSOLE_APPLICATION)

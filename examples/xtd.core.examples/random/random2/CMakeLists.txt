cmake_minimum_required(VERSION 3.20)

project(random2)
find_package(xtd REQUIRED)
add_sources(README.md src/random2.cpp)
target_type(CONSOLE_APPLICATION)

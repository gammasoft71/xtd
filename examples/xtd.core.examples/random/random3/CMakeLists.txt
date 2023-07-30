cmake_minimum_required(VERSION 3.5)

project(random3)
find_package(xtd REQUIRED)
add_sources(README.md src/random3.cpp)
target_type(CONSOLE_APPLICATION)

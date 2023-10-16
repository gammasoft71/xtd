cmake_minimum_required(VERSION 3.20)

project(barrier_simple)
find_package(xtd REQUIRED)
add_sources(README.md src/barrier_simple.cpp)
target_type(CONSOLE_APPLICATION)

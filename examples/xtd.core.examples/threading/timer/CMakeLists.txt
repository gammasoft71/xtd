cmake_minimum_required(VERSION 3.20)

project(timer)
find_package(xtd REQUIRED)
add_sources(README.md src/timer.cpp)
target_type(CONSOLE_APPLICATION)

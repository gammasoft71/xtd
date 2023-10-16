cmake_minimum_required(VERSION 3.20)

project(trace)
find_package(xtd REQUIRED)
add_sources(README.md src/trace.cpp)
target_type(CONSOLE_APPLICATION)

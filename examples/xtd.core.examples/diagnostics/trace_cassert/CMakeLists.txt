cmake_minimum_required(VERSION 3.5)

project(trace_cassert)
find_package(xtd REQUIRED)
add_sources(README.md src/trace_cassert.cpp)
target_type(CONSOLE_APPLICATION)

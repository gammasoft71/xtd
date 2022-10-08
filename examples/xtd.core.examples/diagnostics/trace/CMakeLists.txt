cmake_minimum_required(VERSION 3.3)

project(trace)
find_package(xtd REQUIRED)
add_sources(src/trace.cpp)
target_type(CONSOLE_APPLICATION)

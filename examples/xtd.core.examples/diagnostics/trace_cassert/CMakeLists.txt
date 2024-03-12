cmake_minimum_required(VERSION 3.20)

project(trace_cassert)
find_package(xtd REQUIRED)
add_sources(src/trace_cassert.cpp)
target_type(CONSOLE_APPLICATION)

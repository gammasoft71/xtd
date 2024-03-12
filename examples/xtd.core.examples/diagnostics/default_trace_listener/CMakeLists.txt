cmake_minimum_required(VERSION 3.20)

project(default_trace_listener)
find_package(xtd REQUIRED)
add_sources(src/default_trace_listener.cpp)
target_type(CONSOLE_APPLICATION)

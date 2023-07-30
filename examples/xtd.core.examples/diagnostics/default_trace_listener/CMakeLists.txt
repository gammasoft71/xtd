cmake_minimum_required(VERSION 3.5)

project(default_trace_listener)
find_package(xtd REQUIRED)
add_sources(README.md src/default_trace_listener.cpp)
target_type(CONSOLE_APPLICATION)

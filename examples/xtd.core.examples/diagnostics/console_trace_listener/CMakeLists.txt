cmake_minimum_required(VERSION 3.3)

project(console_trace_listener)
find_package(xtd REQUIRED)
add_sources(src/console_trace_listener.cpp)
target_type(CONSOLE_APPLICATION)

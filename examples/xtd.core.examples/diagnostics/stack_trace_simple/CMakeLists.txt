cmake_minimum_required(VERSION 3.20)

project(stack_trace_simple)
find_package(xtd REQUIRED)
add_sources(src/stack_trace_simple.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.5)

project(stack_trace_simple)
find_package(xtd REQUIRED)
add_sources(README.md src/stack_trace_simple.cpp)
target_type(CONSOLE_APPLICATION)

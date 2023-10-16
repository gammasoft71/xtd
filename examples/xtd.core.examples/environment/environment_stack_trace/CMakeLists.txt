cmake_minimum_required(VERSION 3.20)

project(environment_stack_trace)
find_package(xtd REQUIRED)
add_sources(README.md src/environment_stack_trace.cpp)
target_type(CONSOLE_APPLICATION)

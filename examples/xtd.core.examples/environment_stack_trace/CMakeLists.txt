cmake_minimum_required(VERSION 3.3)

project(environment_stack_trace)
find_package(xtd REQUIRED)
add_sources(src/environment_stack_trace.cpp)
target_type(CONSOLE_APPLICATION)

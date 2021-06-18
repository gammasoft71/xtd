cmake_minimum_required(VERSION 3.3)

project(stack_frame)
find_package(xtd REQUIRED)
add_sources(src/stack_frame.cpp)
target_type(CONSOLE_APPLICATION)

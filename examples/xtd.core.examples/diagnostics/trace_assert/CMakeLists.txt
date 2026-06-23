cmake_minimum_required(VERSION 3.20)

project(trace_assert)
find_package(xtd REQUIRED)
add_sources(README.md src/trace_assert.cpp)
target_type(CONSOLE_APPLICATION)

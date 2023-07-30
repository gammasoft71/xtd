cmake_minimum_required(VERSION 3.5)

project(interlocked)
find_package(xtd REQUIRED)
add_sources(README.md src/interlocked.cpp)
target_type(CONSOLE_APPLICATION)

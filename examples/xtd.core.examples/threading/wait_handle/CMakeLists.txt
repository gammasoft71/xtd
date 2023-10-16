cmake_minimum_required(VERSION 3.20)

project(wait_handle)
find_package(xtd REQUIRED)
add_sources(README.md src/wait_handle.cpp)
target_type(CONSOLE_APPLICATION)

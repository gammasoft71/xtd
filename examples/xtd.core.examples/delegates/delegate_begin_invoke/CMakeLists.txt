cmake_minimum_required(VERSION 3.5)

project(delegate_begin_invoke)
find_package(xtd REQUIRED)
add_sources(README.md src/delegate_begin_invoke.cpp)
target_type(CONSOLE_APPLICATION)

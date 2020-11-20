cmake_minimum_required(VERSION 3.3)

project(hello_world_diagnostics2)
find_package(xtd REQUIRED)
add_sources(src/hello_world_diagnostics2.cpp)
target_type(CONSOLE_APPLICATION)

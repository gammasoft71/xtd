cmake_minimum_required(VERSION 3.20)

project(hello_world_png)
find_package(xtd REQUIRED)
add_sources(README.md src/hello_world_png.cpp)
target_type(CONSOLE_APPLICATION)

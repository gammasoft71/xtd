cmake_minimum_required(VERSION 3.3)

project(hello_world_environment)
find_package(xtd REQUIRED)
add_sources(src/hello_world_environment.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(environment)
find_package(xtd REQUIRED)
add_sources(src/environment.cpp)
target_type(CONSOLE_APPLICATION)

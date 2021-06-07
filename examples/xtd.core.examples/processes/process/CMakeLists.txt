cmake_minimum_required(VERSION 3.3)

project(process)
find_package(xtd REQUIRED)
add_sources(src/process.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.20)

project(process)
find_package(xtd REQUIRED)
add_sources(README.md src/process.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.20)

project(timeout)
find_package(xtd REQUIRED)
add_sources(README.md src/timeout.cpp)
target_type(CONSOLE_APPLICATION)

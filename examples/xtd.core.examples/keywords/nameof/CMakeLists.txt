cmake_minimum_required(VERSION 3.20)

project(nameof)
find_package(xtd REQUIRED)
add_sources(README.md src/nameof.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.20)

project(uri)
find_package(xtd REQUIRED)
add_sources(README.md src/uri.cpp)
target_type(CONSOLE_APPLICATION)

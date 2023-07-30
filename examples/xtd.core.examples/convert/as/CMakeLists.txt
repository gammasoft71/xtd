cmake_minimum_required(VERSION 3.5)

project(as)
find_package(xtd REQUIRED)
add_sources(README.md src/as.cpp)
target_type(CONSOLE_APPLICATION)

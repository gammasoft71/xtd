cmake_minimum_required(VERSION 3.20)

project(istringable)
find_package(xtd REQUIRED)
add_sources(README.md src/istringable.cpp)
target_type(CONSOLE_APPLICATION)

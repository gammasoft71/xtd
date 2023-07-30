cmake_minimum_required(VERSION 3.5)

project(csf)
find_package(xtd REQUIRED)
add_sources(README.md src/csf.cpp)
target_type(CONSOLE_APPLICATION)

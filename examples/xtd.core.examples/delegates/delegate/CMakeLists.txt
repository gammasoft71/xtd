cmake_minimum_required(VERSION 3.20)

project(delegate)
find_package(xtd REQUIRED)
add_sources(README.md src/delegate.cpp)
target_type(CONSOLE_APPLICATION)

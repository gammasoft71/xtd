cmake_minimum_required(VERSION 3.3)

project(delegate)
find_package(xtd REQUIRED)
add_sources(src/delegate.cpp)
target_type(CONSOLE_APPLICATION)

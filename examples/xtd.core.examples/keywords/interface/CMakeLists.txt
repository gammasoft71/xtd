cmake_minimum_required(VERSION 3.3)

project(interface)
find_package(xtd REQUIRED)
add_sources(src/interface.cpp)
target_type(CONSOLE_APPLICATION)

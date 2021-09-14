cmake_minimum_required(VERSION 3.3)

project(action3)
find_package(xtd REQUIRED)
add_references(xtd.forms)
add_sources(src/action3.cpp)
target_type(CONSOLE_APPLICATION)

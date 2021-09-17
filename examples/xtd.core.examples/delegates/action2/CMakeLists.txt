cmake_minimum_required(VERSION 3.3)

project(action2)
find_package(xtd REQUIRED)
add_references(xtd.forms)
add_sources(src/action2.cpp)
target_type(CONSOLE_APPLICATION)

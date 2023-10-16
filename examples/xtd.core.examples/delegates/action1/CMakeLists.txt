cmake_minimum_required(VERSION 3.20)

project(action1)
find_package(xtd REQUIRED)
add_references(xtd.forms)
add_sources(README.md src/action1.cpp)
target_type(CONSOLE_APPLICATION)

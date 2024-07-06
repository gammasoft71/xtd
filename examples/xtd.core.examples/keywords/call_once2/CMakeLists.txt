cmake_minimum_required(VERSION 3.20)

project(call_once2)
find_package(xtd REQUIRED)
add_sources(README.md src/call_once2.cpp)
target_type(CONSOLE_APPLICATION)

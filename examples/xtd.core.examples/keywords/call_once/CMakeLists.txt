cmake_minimum_required(VERSION 3.20)

project(call_once)
find_package(xtd REQUIRED)
add_sources(README.md src/call_once.cpp)
target_type(CONSOLE_APPLICATION)

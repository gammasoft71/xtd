cmake_minimum_required(VERSION 3.20)

project(thread)
find_package(xtd REQUIRED)
add_sources(README.md src/thread.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.20)

project(jthread)
find_package(xtd REQUIRED)
add_sources(README.md src/jthread.cpp)
target_type(CONSOLE_APPLICATION)

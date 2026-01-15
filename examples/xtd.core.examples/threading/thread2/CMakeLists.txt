cmake_minimum_required(VERSION 3.20)

project(thread2)
find_package(xtd REQUIRED)
add_sources(README.md src/thread2.cpp)
target_type(CONSOLE_APPLICATION)

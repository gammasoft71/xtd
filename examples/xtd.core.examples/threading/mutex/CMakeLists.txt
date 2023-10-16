cmake_minimum_required(VERSION 3.20)

project(mutex)
find_package(xtd REQUIRED)
add_sources(README.md src/mutex.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.20)

project(tasks)
find_package(xtd REQUIRED)
add_sources(README.md src/tasks.cpp)
target_type(CONSOLE_APPLICATION)

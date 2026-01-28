cmake_minimum_required(VERSION 3.20)

project(task)
find_package(xtd REQUIRED)
add_sources(README.md src/task.cpp)
target_type(CONSOLE_APPLICATION)

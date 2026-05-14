cmake_minimum_required(VERSION 3.20)

project(task_completion_source)
find_package(xtd REQUIRED)
add_sources(README.md src/task_completion_source.cpp)
target_type(CONSOLE_APPLICATION)

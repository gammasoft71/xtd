cmake_minimum_required(VERSION 3.20)

project(task_factory)
find_package(xtd REQUIRED)
add_sources(README.md src/task_factory.cpp)
target_type(CONSOLE_APPLICATION)

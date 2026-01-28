cmake_minimum_required(VERSION 3.20)

project(coroutine_task)
find_package(xtd REQUIRED)
add_sources(README.md src/coroutine_task.cpp)
target_type(CONSOLE_APPLICATION)

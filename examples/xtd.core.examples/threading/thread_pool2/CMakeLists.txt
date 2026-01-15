cmake_minimum_required(VERSION 3.20)

project(thread_pool2)
find_package(xtd REQUIRED)
add_sources(README.md src/thread_pool2.cpp)
target_type(CONSOLE_APPLICATION)

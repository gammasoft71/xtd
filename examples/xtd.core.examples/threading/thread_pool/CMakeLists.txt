cmake_minimum_required(VERSION 3.20)

project(thread_pool)
find_package(xtd REQUIRED)
add_sources(README.md src/thread_pool.cpp)
target_type(CONSOLE_APPLICATION)

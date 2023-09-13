cmake_minimum_required(VERSION 3.5)

project(lock_guard_keyword)
find_package(xtd REQUIRED)
add_sources(README.md src/lock_guard_keyword.cpp)
target_type(CONSOLE_APPLICATION)

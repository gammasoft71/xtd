cmake_minimum_required(VERSION 3.20)

project(lock_guard)
find_package(xtd REQUIRED)
add_sources(README.md src/lock_guard.cpp)
target_type(CONSOLE_APPLICATION)

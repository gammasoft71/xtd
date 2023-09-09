cmake_minimum_required(VERSION 3.5)

project(monitor_lock)
find_package(xtd REQUIRED)
add_sources(README.md src/monitor_lock.cpp)
target_type(CONSOLE_APPLICATION)

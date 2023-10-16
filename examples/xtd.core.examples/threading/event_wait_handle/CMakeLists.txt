cmake_minimum_required(VERSION 3.20)

project(event_wait_handle)
find_package(xtd REQUIRED)
add_sources(README.md src/event_wait_handle.cpp)
target_type(CONSOLE_APPLICATION)

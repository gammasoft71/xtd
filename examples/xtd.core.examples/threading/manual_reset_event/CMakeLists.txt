cmake_minimum_required(VERSION 3.20)

project(manual_reset_event)
find_package(xtd REQUIRED)
add_sources(README.md src/manual_reset_event.cpp)
target_type(CONSOLE_APPLICATION)

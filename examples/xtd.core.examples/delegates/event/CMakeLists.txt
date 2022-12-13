cmake_minimum_required(VERSION 3.3)

project(event)
find_package(xtd REQUIRED)
add_sources(README.md src/event.cpp)
target_type(CONSOLE_APPLICATION)

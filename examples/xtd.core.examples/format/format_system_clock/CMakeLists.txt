cmake_minimum_required(VERSION 3.20)

project(format_system_clock)
find_package(xtd REQUIRED)
add_sources(README.md src/format_system_clock.cpp)
target_type(CONSOLE_APPLICATION)

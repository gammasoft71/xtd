cmake_minimum_required(VERSION 3.20)

project(timers_timer)
find_package(xtd REQUIRED)
add_sources(README.md src/timers_timer.cpp)
target_type(CONSOLE_APPLICATION)

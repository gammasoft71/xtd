cmake_minimum_required(VERSION 3.20)

project(environment_tick_count)
find_package(xtd REQUIRED)
add_sources(README.md src/environment_tick_count.cpp)
target_type(CONSOLE_APPLICATION)

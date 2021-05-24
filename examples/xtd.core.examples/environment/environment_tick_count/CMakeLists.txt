cmake_minimum_required(VERSION 3.3)

project(environment_tick_count)
find_package(xtd REQUIRED)
add_sources(src/environment_tick_count.cpp)
target_type(CONSOLE_APPLICATION)

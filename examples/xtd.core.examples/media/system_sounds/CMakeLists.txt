cmake_minimum_required(VERSION 3.3)

project(system_sounds)
find_package(xtd REQUIRED)
add_sources(src/system_sounds.cpp)
target_type(CONSOLE_APPLICATION)

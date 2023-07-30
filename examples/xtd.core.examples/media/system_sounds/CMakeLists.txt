cmake_minimum_required(VERSION 3.5)

project(system_sounds)
find_package(xtd REQUIRED)
add_sources(README.md src/system_sounds.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(console_firework)
find_package(xtd REQUIRED)
add_sources(README.md src/console_firework.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.20)

project(startup3)
find_package(xtd REQUIRED)
add_sources(README.md src/startup3.cpp)
target_type(CONSOLE_APPLICATION)

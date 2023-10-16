cmake_minimum_required(VERSION 3.20)

# Project
project(target_type)
find_package(xtd REQUIRED)

# Sources
add_sources(README.md src/target_type.cpp)

# Target
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.3)

# Project
project(target_type)
find_package(xtd REQUIRED)

# Sources
add_sources(src/target_type.cpp)

# Target
target_type(CONSOLE_APPLICATION)

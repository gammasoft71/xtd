cmake_minimum_required(VERSION 3.3)

# Project
project(resources_example)
find_package(xtd REQUIRED)

# Sources
add_sources(resources_example.cpp)

# Target
target_type(GUI_APPLICATION)

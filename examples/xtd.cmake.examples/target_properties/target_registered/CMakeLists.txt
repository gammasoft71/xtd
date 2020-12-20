cmake_minimum_required(VERSION 3.3)

# Project
project(target_registered)
find_package(xtd REQUIRED)

# Application properties
target_registered(OFF)

# Sources
add_sources(src/target_registered.cpp)

# Target
target_type(GUI_APPLICATION)

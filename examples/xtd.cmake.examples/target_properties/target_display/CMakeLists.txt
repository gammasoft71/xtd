cmake_minimum_required(VERSION 3.20)

# Project
project(target_display)
find_package(xtd REQUIRED)

# Application properties
target_display(ON)

# Sources
add_sources(README.md src/target_display.cpp)

# Target
target_type(GUI_APPLICATION)

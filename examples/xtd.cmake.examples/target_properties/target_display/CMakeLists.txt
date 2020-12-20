cmake_minimum_required(VERSION 3.3)

# Project
project(target_display)
find_package(xtd REQUIRED)

# Application properties
target_display(ON)

# Sources
add_sources(src/target_display.cpp)

# Target
target_type(GUI_APPLICATION)

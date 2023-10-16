cmake_minimum_required(VERSION 3.20)

# Project
project(target_icon)
find_package(xtd REQUIRED)

# Application properties
target_icon(resources/xtd_forms)

# Sources
add_sources(README.md src/target_icon.cpp)

# Target
target_type(GUI_APPLICATION)

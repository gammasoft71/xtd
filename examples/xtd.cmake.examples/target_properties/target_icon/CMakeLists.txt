cmake_minimum_required(VERSION 3.3)

# Project
project(target_icon)
find_package(xtd REQUIRED)

# Application properties
target_icon(resources/xtd_forms)

# Sources
add_sources(src/target_icon.cpp)

# Target
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.3)

# Project
project(settings_example)
find_package(xtd REQUIRED)

# Sources
add_sources(settings_example.cpp)

# Target
target_type(GUI_APPLICATION)

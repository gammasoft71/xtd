cmake_minimum_required(VERSION 3.3)

# Project
project(resources_command)
find_package(xtd REQUIRED)

# Sources
add_sources(resources_command.cpp)

# Target
target_type(GUI_APPLICATION)

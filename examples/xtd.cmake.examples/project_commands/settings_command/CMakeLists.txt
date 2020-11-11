cmake_minimum_required(VERSION 3.3)

# Project
project(settings_command)
find_package(xtd REQUIRED)

# Sources
add_sources(settings_command.cpp)

# Target
target_type(GUI_APPLICATION)

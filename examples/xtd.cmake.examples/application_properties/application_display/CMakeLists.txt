cmake_minimum_required(VERSION 3.3)

# Project
project(application_display)
find_package(xtd REQUIRED)

# Application properties
application_display(ON)

# Sources
add_sources(application_display.cpp)

# Target
target_type(GUI_APPLICATION)

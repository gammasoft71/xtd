cmake_minimum_required(VERSION 3.20)

# Project
project(gui_application)
find_package(xtd REQUIRED)

# Sources
add_sources(gui_application.cpp)

# Target
target_type(GUI_APPLICATION)

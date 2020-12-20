cmake_minimum_required(VERSION 3.3)

# Project
project(application_icon)
find_package(xtd REQUIRED)

# Application properties
application_icon(resources/xtd_forms)

# Sources
add_sources(src/application_icon.cpp)

# Target
target_type(GUI_APPLICATION)

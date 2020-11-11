cmake_minimum_required(VERSION 3.3)

# Project
project(application_registered)
find_package(xtd REQUIRED)

# Application properties
application_registered(OFF)

# Sources
add_sources(application_registered.cpp)

# Target
target_type(GUI_APPLICATION)

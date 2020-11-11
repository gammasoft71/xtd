cmake_minimum_required(VERSION 3.3)

# Project
project(application_startup)
find_package(xtd REQUIRED)

# Application properties
application_startup("application_startup::program" application_startup.cpp)

# Sources
add_sources(application_startup.cpp)

# Target
target_type(GUI_APPLICATION)

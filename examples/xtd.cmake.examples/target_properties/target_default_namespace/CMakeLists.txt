cmake_minimum_required(VERSION 3.3)

# Project
project(target_default_namespace)
find_package(xtd REQUIRED)

# Application properties
target_default_namespace(other_namespace)

# Sources
add_sources(src/target_default_namespace.cpp)

# Target
target_type(GUI_APPLICATION)

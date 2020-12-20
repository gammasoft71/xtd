cmake_minimum_required(VERSION 3.3)

# Project
project(target_name)
find_package(xtd REQUIRED)

# Application properties
target_name("xtd_forms_target")

# Sources
add_sources(src/target_name.cpp)

# Target
target_type(GUI_APPLICATION)

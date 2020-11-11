cmake_minimum_required(VERSION 3.3)

# Project
project(build_output_directory)
find_package(xtd REQUIRED)

# Build options
build_output_directory("${USER_DIRECTORY}/Output")

# Sources
add_sources(build_output_directory.cpp)

# Target
target_type(GUI_APPLICATION)

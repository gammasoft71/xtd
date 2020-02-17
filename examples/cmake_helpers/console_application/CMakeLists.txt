cmake_minimum_required(VERSION 3.3)

# Project
project(console_application)
find_package(xtd REQUIRED)

# Sources
add_sources(console_application.cpp)

# Target
target_type(CONSOLE_APPLICATION)

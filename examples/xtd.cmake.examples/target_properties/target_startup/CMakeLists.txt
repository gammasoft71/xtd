cmake_minimum_required(VERSION 3.20)

# Project
project(target_startup)
find_package(xtd REQUIRED)

# Application properties
target_startup("target_startup::program::main" src/target_startup.cpp)

# Sources
add_sources(README.md src/target_startup.cpp)

# Target
target_type(GUI_APPLICATION)

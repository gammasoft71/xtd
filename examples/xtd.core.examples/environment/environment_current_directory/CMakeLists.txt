cmake_minimum_required(VERSION 3.20)

project(environment_current_directory)
find_package(xtd REQUIRED)
add_sources(README.md src/environment_current_directory.cpp)
target_type(CONSOLE_APPLICATION)

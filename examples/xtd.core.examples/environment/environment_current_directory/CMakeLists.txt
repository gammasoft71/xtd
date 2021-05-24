cmake_minimum_required(VERSION 3.3)

project(environment_current_directory)
find_package(xtd REQUIRED)
add_sources(src/environment_current_directory.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.20)

project(environment_expand_environment_variables)
find_package(xtd REQUIRED)
add_sources(README.md src/environment_expand_environment_variables.cpp)
target_type(CONSOLE_APPLICATION)

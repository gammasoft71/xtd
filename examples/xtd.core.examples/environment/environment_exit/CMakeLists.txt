cmake_minimum_required(VERSION 3.20)

project(environment_exit)
find_package(xtd REQUIRED)
add_sources(README.md src/environment_exit.cpp)
target_type(CONSOLE_APPLICATION)

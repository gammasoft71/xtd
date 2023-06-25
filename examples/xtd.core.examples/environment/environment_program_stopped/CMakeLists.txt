cmake_minimum_required(VERSION 3.3)

project(environment_program_stopped)
find_package(xtd REQUIRED)
add_sources(README.md src/environment_program_stopped.cpp)
target_type(CONSOLE_APPLICATION)

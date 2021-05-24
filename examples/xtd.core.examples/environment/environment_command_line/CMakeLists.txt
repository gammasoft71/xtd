cmake_minimum_required(VERSION 3.3)

project(environment_command_line)
find_package(xtd REQUIRED)
add_sources(src/environment_command_line.cpp)
target_type(CONSOLE_APPLICATION)

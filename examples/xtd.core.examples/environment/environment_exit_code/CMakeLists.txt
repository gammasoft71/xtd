cmake_minimum_required(VERSION 3.3)

project(environment_exit_code)
find_package(xtd REQUIRED)
add_sources(src/environment_exit_code.cpp)
target_type(CONSOLE_APPLICATION)

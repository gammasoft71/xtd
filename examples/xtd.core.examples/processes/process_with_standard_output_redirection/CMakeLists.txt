cmake_minimum_required(VERSION 3.20)

project(process_with_standard_output_redirection)
find_package(xtd REQUIRED)
add_sources(README.md src/process_with_standard_output_redirection.cpp)
target_type(CONSOLE_APPLICATION)

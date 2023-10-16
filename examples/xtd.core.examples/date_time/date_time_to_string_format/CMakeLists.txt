cmake_minimum_required(VERSION 3.20)

project(date_time_to_string_format)
find_package(xtd REQUIRED)
add_sources(README.md src/date_time_to_string_format.cpp)
target_type(CONSOLE_APPLICATION)

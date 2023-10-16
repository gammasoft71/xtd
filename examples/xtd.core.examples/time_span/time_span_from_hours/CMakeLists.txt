cmake_minimum_required(VERSION 3.20)

project(time_span_from_hours)
find_package(xtd REQUIRED)
add_sources(README.md src/time_span_from_hours.cpp)
target_type(CONSOLE_APPLICATION)

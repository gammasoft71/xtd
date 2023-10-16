cmake_minimum_required(VERSION 3.20)

project(time_span_from_days)
find_package(xtd REQUIRED)
add_sources(README.md src/time_span_from_days.cpp)
target_type(CONSOLE_APPLICATION)

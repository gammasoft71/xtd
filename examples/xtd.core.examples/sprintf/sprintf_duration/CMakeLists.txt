cmake_minimum_required(VERSION 3.3)

project(sprintf_duration)
find_package(xtd REQUIRED)
add_sources(src/sprintf_duration.cpp)
target_type(CONSOLE_APPLICATION)

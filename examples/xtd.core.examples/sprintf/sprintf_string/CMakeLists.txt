cmake_minimum_required(VERSION 3.20)

project(sprintf_string)
find_package(xtd REQUIRED)
add_sources(src/sprintf_string.cpp)
target_type(CONSOLE_APPLICATION)

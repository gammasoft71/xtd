cmake_minimum_required(VERSION 3.20)

project(sprintf_numeric)
find_package(xtd REQUIRED)
add_sources(README.md src/sprintf_numeric.cpp)
target_type(CONSOLE_APPLICATION)

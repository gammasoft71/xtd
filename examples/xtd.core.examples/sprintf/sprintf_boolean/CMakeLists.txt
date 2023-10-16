cmake_minimum_required(VERSION 3.20)

project(sprintf_boolean)
find_package(xtd REQUIRED)
add_sources(README.md src/sprintf_boolean.cpp)
target_type(CONSOLE_APPLICATION)

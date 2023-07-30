cmake_minimum_required(VERSION 3.5)

project(sprintf_class)
find_package(xtd REQUIRED)
add_sources(README.md src/sprintf_class.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.20)

project(iequatable)
find_package(xtd REQUIRED)
add_sources(README.md src/iequatable.cpp)
target_type(CONSOLE_APPLICATION)

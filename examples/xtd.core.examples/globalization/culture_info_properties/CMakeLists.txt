cmake_minimum_required(VERSION 3.20)

project(culture_info_properties)
find_package(xtd REQUIRED)
add_sources(README.md src/culture_info_properties.cpp)
target_type(CONSOLE_APPLICATION)

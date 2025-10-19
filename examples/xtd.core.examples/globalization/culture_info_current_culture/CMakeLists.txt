cmake_minimum_required(VERSION 3.20)

project(culture_info_current_culture)
find_package(xtd REQUIRED)
add_sources(README.md src/culture_info_current_culture.cpp)
target_type(CONSOLE_APPLICATION)

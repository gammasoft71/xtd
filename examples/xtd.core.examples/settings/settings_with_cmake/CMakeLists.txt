cmake_minimum_required(VERSION 3.20)

project(settings_with_cmake)
find_package(xtd REQUIRED)
add_sources(README.md src/settings_with_cmake.cpp)
target_type(CONSOLE_APPLICATION)

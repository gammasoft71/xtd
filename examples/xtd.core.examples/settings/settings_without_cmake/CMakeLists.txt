cmake_minimum_required(VERSION 3.20)

project(settings_without_cmake)
find_package(xtd REQUIRED)
add_sources(README.md src/settings_without_cmake.cpp)
target_type(CONSOLE_APPLICATION)

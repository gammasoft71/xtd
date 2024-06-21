cmake_minimum_required(VERSION 3.20)

project(file_settings)
find_package(xtd REQUIRED)
add_sources(README.md src/file_settings.cpp)
target_type(CONSOLE_APPLICATION)

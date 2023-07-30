cmake_minimum_required(VERSION 3.5)

project(drive_info)
find_package(xtd REQUIRED)
add_sources(README.md src/drive_info.cpp)
target_type(CONSOLE_APPLICATION)

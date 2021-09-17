cmake_minimum_required(VERSION 3.3)

project(version)
find_package(xtd REQUIRED)
add_sources(src/version.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.20)

project(version)
find_package(xtd REQUIRED)
add_sources(src/version.cpp)
target_type(CONSOLE_APPLICATION)

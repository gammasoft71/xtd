cmake_minimum_required(VERSION 3.3)

project(startup)
find_package(xtd REQUIRED)
add_sources(startup.cpp)
target_type(CONSOLE_APPLICATION)

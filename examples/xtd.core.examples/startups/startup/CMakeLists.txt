cmake_minimum_required(VERSION 3.20)

project(startup)
find_package(xtd REQUIRED)
add_sources(README.md src/startup.cpp)
target_type(CONSOLE_APPLICATION)

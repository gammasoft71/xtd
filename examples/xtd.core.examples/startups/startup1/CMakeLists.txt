cmake_minimum_required(VERSION 3.5)

project(startup1)
find_package(xtd REQUIRED)
add_sources(README.md src/startup1.cpp)
target_type(CONSOLE_APPLICATION)

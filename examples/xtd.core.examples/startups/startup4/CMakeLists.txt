cmake_minimum_required(VERSION 3.20)

project(startup4)
find_package(xtd REQUIRED)
add_sources(README.md src/startup4.cpp)
target_type(CONSOLE_APPLICATION)

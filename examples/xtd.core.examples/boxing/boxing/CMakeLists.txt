cmake_minimum_required(VERSION 3.5)

project(boxing)
find_package(xtd REQUIRED)
add_sources(README.md src/boxing.cpp)
target_type(CONSOLE_APPLICATION)

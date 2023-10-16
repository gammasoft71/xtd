cmake_minimum_required(VERSION 3.20)

project(main4)
find_package(xtd REQUIRED)
add_sources(README.md src/main4.cpp)
target_type(CONSOLE_APPLICATION)

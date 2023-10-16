cmake_minimum_required(VERSION 3.20)

project(using)
find_package(xtd REQUIRED)
add_sources(README.md src/using.cpp)
target_type(CONSOLE_APPLICATION)

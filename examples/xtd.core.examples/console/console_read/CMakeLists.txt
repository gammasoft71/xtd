cmake_minimum_required(VERSION 3.5)

project(console_read)
find_package(xtd REQUIRED)
add_sources(README.md src/console_read.cpp)
target_type(CONSOLE_APPLICATION)

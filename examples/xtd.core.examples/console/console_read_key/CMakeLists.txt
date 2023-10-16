cmake_minimum_required(VERSION 3.20)

project(console_read_key)
find_package(xtd REQUIRED)
add_sources(README.md src/console_read_key.cpp)
target_type(CONSOLE_APPLICATION)

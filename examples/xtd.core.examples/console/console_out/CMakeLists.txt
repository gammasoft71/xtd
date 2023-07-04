cmake_minimum_required(VERSION 3.3)

project(console_out)
find_package(xtd REQUIRED)
add_sources(README.md src/console_out.cpp)
target_type(CONSOLE_APPLICATION)

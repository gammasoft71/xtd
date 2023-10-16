cmake_minimum_required(VERSION 3.20)

project(console_unicode)
find_package(xtd REQUIRED)
add_sources(README.md src/console_unicode.cpp)
target_type(CONSOLE_APPLICATION)

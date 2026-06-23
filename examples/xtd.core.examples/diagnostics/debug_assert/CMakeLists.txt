cmake_minimum_required(VERSION 3.20)

project(debug_assert)
find_package(xtd REQUIRED)
add_sources(README.md src/debug_assert.cpp)
target_type(CONSOLE_APPLICATION)

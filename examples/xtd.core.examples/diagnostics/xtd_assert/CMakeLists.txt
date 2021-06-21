cmake_minimum_required(VERSION 3.3)

project(xtd_assert)
find_package(xtd REQUIRED)
add_sources(src/xtd_assert.cpp)
target_type(CONSOLE_APPLICATION)

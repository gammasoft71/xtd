cmake_minimum_required(VERSION 3.3)

project(block_scope)
find_package(xtd REQUIRED)
add_sources(block_scope.cpp)
target_type(CONSOLE_APPLICATION)

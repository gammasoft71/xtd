cmake_minimum_required(VERSION 3.20)

project(block_scope)
find_package(xtd REQUIRED)
add_sources(src/block_scope.cpp)
target_type(CONSOLE_APPLICATION)

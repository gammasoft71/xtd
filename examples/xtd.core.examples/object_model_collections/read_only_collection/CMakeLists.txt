cmake_minimum_required(VERSION 3.20)

project(read_only_collection)
find_package(xtd REQUIRED)
add_sources(README.md src/read_only_collection.cpp)
target_type(CONSOLE_APPLICATION)

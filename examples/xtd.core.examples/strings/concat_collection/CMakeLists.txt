cmake_minimum_required(VERSION 3.20)

project(concat_collection)
find_package(xtd REQUIRED)
add_sources(src/concat_collection.cpp)
target_type(CONSOLE_APPLICATION)

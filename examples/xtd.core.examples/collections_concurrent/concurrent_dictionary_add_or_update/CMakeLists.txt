cmake_minimum_required(VERSION 3.20)

project(concurrent_dictionary_add_or_update)
find_package(xtd REQUIRED)
add_sources(README.md src/concurrent_dictionary_add_or_update.cpp)
target_type(CONSOLE_APPLICATION)

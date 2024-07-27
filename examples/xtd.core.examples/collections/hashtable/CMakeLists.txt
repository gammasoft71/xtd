cmake_minimum_required(VERSION 3.20)

project(hashtable)
find_package(xtd REQUIRED)
add_sources(README.md src/hashtable.cpp)
target_type(CONSOLE_APPLICATION)

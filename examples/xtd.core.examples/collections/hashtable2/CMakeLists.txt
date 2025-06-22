cmake_minimum_required(VERSION 3.20)

project(hashtable2)
find_package(xtd REQUIRED)
add_sources(README.md src/hashtable2.cpp)
target_type(CONSOLE_APPLICATION)

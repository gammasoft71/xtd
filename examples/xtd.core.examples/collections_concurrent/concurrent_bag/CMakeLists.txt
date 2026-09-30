cmake_minimum_required(VERSION 3.20)

project(concurrent_bag)
find_package(xtd REQUIRED)
add_sources(README.md src/concurrent_bag.cpp)
target_type(CONSOLE_APPLICATION)

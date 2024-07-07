cmake_minimum_required(VERSION 3.20)

project(object_memberwise_clone)
find_package(xtd REQUIRED)
add_sources(README.md src/object_memberwise_clone.cpp)
target_type(CONSOLE_APPLICATION)

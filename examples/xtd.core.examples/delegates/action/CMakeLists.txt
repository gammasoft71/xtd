cmake_minimum_required(VERSION 3.3)

project(action)
find_package(xtd REQUIRED)
add_sources(src/action.cpp)
target_type(CONSOLE_APPLICATION)

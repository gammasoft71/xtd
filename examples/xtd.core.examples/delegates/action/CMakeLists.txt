cmake_minimum_required(VERSION 3.20)

project(action)
find_package(xtd REQUIRED)
add_sources(src/action.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(using)
find_package(xtd REQUIRED)
add_sources(using.cpp)
target_type(CONSOLE_APPLICATION)

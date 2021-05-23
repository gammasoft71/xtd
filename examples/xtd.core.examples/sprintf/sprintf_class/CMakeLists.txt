cmake_minimum_required(VERSION 3.3)

project(sprintf_class)
find_package(xtd REQUIRED)
add_sources(src/sprintf_class.cpp)
target_type(CONSOLE_APPLICATION)

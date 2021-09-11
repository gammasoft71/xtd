cmake_minimum_required(VERSION 3.3)

project(as)
find_package(xtd REQUIRED)
add_sources(src/as.cpp)
target_type(CONSOLE_APPLICATION)

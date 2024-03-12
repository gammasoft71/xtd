cmake_minimum_required(VERSION 3.20)

project(as)
find_package(xtd REQUIRED)
add_sources(src/as.cpp)
target_type(CONSOLE_APPLICATION)

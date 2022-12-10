cmake_minimum_required(VERSION 3.3)

project(iprogress)
find_package(xtd REQUIRED)
add_sources(src/iprogress.cpp)
target_type(CONSOLE_APPLICATION)

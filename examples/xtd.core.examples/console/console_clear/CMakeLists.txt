cmake_minimum_required(VERSION 3.3)

project(console_clear)
find_package(xtd REQUIRED)
add_sources(src/console_clear.cpp)
target_type(CONSOLE_APPLICATION)

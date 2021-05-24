cmake_minimum_required(VERSION 3.3)

project(console_read_key)
find_package(xtd REQUIRED)
add_sources(src/console_read_key.cpp)
target_type(CONSOLE_APPLICATION)

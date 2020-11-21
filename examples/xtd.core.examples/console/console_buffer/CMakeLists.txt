cmake_minimum_required(VERSION 3.3)

project(console_buffer)
find_package(xtd REQUIRED)
add_sources(src/console_buffer.cpp)
target_type(CONSOLE_APPLICATION)

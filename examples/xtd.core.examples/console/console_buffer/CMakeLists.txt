cmake_minimum_required(VERSION 3.20)

project(console_buffer)
find_package(xtd REQUIRED)
add_sources(src/console_buffer.cpp)
target_type(CONSOLE_APPLICATION)

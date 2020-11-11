cmake_minimum_required(VERSION 3.3)

project(console_in_out)
find_package(xtd REQUIRED)
add_sources(src/console_in_out.cpp)
target_type(CONSOLE_APPLICATION)

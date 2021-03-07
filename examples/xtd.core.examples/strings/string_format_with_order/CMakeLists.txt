cmake_minimum_required(VERSION 3.3)

project(string_format_with_order)
find_package(xtd REQUIRED)
add_sources(src/string_format_with_order.cpp)
target_type(CONSOLE_APPLICATION)

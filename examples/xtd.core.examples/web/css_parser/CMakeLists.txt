cmake_minimum_required(VERSION 3.3)

project(css_parser)
find_package(xtd REQUIRED)
add_sources(src/css_parser.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(format_enum_class_flags)
find_package(xtd REQUIRED)
add_sources(src/format_enum_class_flags.cpp)
target_type(CONSOLE_APPLICATION)

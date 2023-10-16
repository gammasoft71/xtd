cmake_minimum_required(VERSION 3.20)

project(format_enum_class_flags_without_helper)
find_package(xtd REQUIRED)
add_sources(README.md src/format_enum_class_flags_without_helper.cpp)
target_type(CONSOLE_APPLICATION)

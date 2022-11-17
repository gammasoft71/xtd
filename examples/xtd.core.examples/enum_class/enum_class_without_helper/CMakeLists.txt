cmake_minimum_required(VERSION 3.3)

project(enum_class_without_helper)
find_package(xtd REQUIRED)
add_sources(src/enum_class_without_helper.cpp)
target_type(CONSOLE_APPLICATION)

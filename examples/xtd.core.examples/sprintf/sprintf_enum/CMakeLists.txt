cmake_minimum_required(VERSION 3.20)

project(sprintf_enum)
find_package(xtd REQUIRED)
add_sources(src/sprintf_enum.cpp)
target_type(CONSOLE_APPLICATION)

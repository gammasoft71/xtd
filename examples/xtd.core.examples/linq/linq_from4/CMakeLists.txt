cmake_minimum_required(VERSION 3.20)

project(linq_from4)
find_package(xtd REQUIRED)
add_sources(README.md src/linq_from4.cpp)
target_type(CONSOLE_APPLICATION)

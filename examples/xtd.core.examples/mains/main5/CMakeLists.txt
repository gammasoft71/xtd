cmake_minimum_required(VERSION 3.20)

project(main5)
find_package(xtd REQUIRED)
add_sources(README.md src/main5.cpp)
target_type(CONSOLE_APPLICATION)

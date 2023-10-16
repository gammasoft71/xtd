cmake_minimum_required(VERSION 3.20)

project(assert_)
find_package(xtd REQUIRED)
add_sources(src/assert_.cpp)
target_type(CONSOLE_APPLICATION)

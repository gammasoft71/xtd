cmake_minimum_required(VERSION 3.3)

project(assert_)
find_package(xtd REQUIRED)
add_sources(src/assert_.cpp)
target_type(CONSOLE_APPLICATION)

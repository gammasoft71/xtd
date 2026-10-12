cmake_minimum_required(VERSION 3.20)

project(parallel_for_)
find_package(xtd REQUIRED)
add_sources(README.md src/parallel_for_.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.20)

project(array_rank_2_and_mdspan)
find_package(xtd REQUIRED)
add_sources(README.md src/array_rank_2_and_mdspan.cpp)
target_type(CONSOLE_APPLICATION)

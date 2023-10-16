cmake_minimum_required(VERSION 3.20)

project(mixing_std_and_xtd_threads)
find_package(xtd REQUIRED)
add_sources(README.md src/mixing_std_and_xtd_threads.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.20)

project(environment_fail_fast)
find_package(xtd REQUIRED)
add_sources(README.md src/environment_fail_fast.cpp)
target_type(CONSOLE_APPLICATION)

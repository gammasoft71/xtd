cmake_minimum_required(VERSION 3.20)

project(iasync_result)
find_package(xtd REQUIRED)
add_sources(README.md src/iasync_result.cpp)
target_type(CONSOLE_APPLICATION)

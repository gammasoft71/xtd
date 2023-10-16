cmake_minimum_required(VERSION 3.20)

project(network_stream)
find_package(xtd REQUIRED)
add_sources(README.md src/network_stream.cpp)
target_type(CONSOLE_APPLICATION)

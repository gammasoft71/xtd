cmake_minimum_required(VERSION 3.20)

project(delegate_multicast)
find_package(xtd REQUIRED)
add_sources(README.md src/delegate_multicast.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(delegate_multicast)
find_package(xtd REQUIRED)
add_sources(src/delegate_multicast.cpp)
target_type(CONSOLE_APPLICATION)

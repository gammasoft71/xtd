cmake_minimum_required(VERSION 3.5)

project(ip_address)
find_package(xtd REQUIRED)
add_sources(README.md src/ip_address.cpp)
target_type(CONSOLE_APPLICATION)

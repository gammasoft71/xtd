cmake_minimum_required(VERSION 3.3)

project(wconsole)
find_package(xtd REQUIRED)
add_sources(src/wconsole.cpp)
target_type(CONSOLE_APPLICATION)

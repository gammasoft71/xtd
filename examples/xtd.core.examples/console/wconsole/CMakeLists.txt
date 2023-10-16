cmake_minimum_required(VERSION 3.20)

project(wconsole)
find_package(xtd REQUIRED)
add_sources(README.md src/wconsole.cpp)
target_type(CONSOLE_APPLICATION)

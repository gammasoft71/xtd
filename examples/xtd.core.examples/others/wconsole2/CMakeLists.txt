cmake_minimum_required(VERSION 3.20)

project(wconsole2)
find_package(xtd REQUIRED)
add_sources(README.md src/wconsole2.cpp)
target_type(CONSOLE_APPLICATION)

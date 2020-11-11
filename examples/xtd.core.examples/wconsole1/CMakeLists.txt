cmake_minimum_required(VERSION 3.3)

project(wconsole1)
find_package(xtd REQUIRED)
add_sources(src/wconsole1.cpp)
target_type(CONSOLE_APPLICATION)

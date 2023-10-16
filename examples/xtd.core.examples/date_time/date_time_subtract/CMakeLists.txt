cmake_minimum_required(VERSION 3.20)

project(date_time_subtract)
find_package(xtd REQUIRED)
add_sources(README.md src/date_time_subtract.cpp)
target_type(CONSOLE_APPLICATION)

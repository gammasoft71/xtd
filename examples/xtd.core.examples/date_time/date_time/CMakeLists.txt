cmake_minimum_required(VERSION 3.3)

project(date_time)
find_package(xtd REQUIRED)
add_sources(README.md src/date_time.cpp)
target_type(CONSOLE_APPLICATION)

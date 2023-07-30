cmake_minimum_required(VERSION 3.5)

project(date_time_add_days)
find_package(xtd REQUIRED)
add_sources(README.md src/date_time_add_days.cpp)
target_type(CONSOLE_APPLICATION)

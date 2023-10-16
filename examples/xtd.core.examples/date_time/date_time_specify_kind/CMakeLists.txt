cmake_minimum_required(VERSION 3.20)

project(date_time_specify_kind)
find_package(xtd REQUIRED)
add_sources(README.md src/date_time_specify_kind.cpp)
target_type(CONSOLE_APPLICATION)

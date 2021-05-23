cmake_minimum_required(VERSION 3.3)

project(sprintf_date_time)
find_package(xtd REQUIRED)
add_sources(src/sprintf_date_time.cpp)
target_type(CONSOLE_APPLICATION)

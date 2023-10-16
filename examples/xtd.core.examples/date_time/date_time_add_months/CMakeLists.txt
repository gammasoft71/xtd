cmake_minimum_required(VERSION 3.20)

project(date_time_add_months)
find_package(xtd REQUIRED)
add_sources(README.md src/date_time_add_months.cpp)
target_type(CONSOLE_APPLICATION)

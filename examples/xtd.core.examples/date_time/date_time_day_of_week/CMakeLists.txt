cmake_minimum_required(VERSION 3.20)

project(date_time_day_of_week)
find_package(xtd REQUIRED)
add_sources(README.md src/date_time_day_of_week.cpp)
target_type(CONSOLE_APPLICATION)

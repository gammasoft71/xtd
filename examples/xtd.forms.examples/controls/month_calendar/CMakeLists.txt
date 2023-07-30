cmake_minimum_required(VERSION 3.5)

project(month_calendar)
find_package(xtd REQUIRED)
add_sources(README.md src/month_calendar.cpp)
target_type(GUI_APPLICATION)

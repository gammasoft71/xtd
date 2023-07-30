cmake_minimum_required(VERSION 3.5)

project(system_report)
find_package(xtd REQUIRED)
add_references(xtd)
add_sources(README.md src/system_report.cpp)
target_type(GUI_APPLICATION)

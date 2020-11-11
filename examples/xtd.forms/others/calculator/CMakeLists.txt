cmake_minimum_required(VERSION 3.3)

project(calculator)
find_package(xtd REQUIRED)
add_sources(src/calculator.cpp)
target_type(GUI_APPLICATION)

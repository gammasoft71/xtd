cmake_minimum_required(VERSION 3.20)

project(countries)
find_package(xtd REQUIRED)
add_sources(README.md src/countries.cpp)
target_type(GUI_APPLICATION)

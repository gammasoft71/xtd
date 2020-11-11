cmake_minimum_required(VERSION 3.3)

project(countries)
find_package(xtd REQUIRED)
add_sources(src/countries.cpp)
target_type(GUI_APPLICATION)

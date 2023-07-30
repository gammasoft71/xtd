cmake_minimum_required(VERSION 3.5)

project(choice)
find_package(xtd REQUIRED)
add_sources(README.md src/choice.cpp)
target_type(GUI_APPLICATION)

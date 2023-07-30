cmake_minimum_required(VERSION 3.5)

project(tutorial_communicate)
find_package(xtd REQUIRED)
add_sources(README.md src/tutorial_communicate.cpp)
target_type(GUI_APPLICATION)

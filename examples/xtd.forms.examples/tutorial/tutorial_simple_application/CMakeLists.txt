cmake_minimum_required(VERSION 3.5)

project(tutorial_simple_application)
find_package(xtd REQUIRED)
add_sources(README.md src/tutorial_simple_application.cpp)
target_type(GUI_APPLICATION)

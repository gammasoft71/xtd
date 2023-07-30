cmake_minimum_required(VERSION 3.5)

project(tutorial_button)
find_package(xtd REQUIRED)
add_sources(README.md src/tutorial_button.cpp)
target_type(GUI_APPLICATION)

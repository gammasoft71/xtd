cmake_minimum_required(VERSION 3.20)

project(tutorial_application_icon)
find_package(xtd REQUIRED)
add_sources(README.md src/tutorial_application_icon.cpp)
target_type(GUI_APPLICATION)

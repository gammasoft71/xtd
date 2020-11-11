cmake_minimum_required(VERSION 3.3)

project(tutorial_simple_application)
find_package(xtd.forms REQUIRED)
add_sources(src/simple.cpp)
target_type(GUI_APPLICATION)

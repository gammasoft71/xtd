cmake_minimum_required(VERSION 3.3)

project(tutorial_communicate)
find_package(xtd.forms REQUIRED)
add_sources(src/communicate.cpp)
target_type(GUI_APPLICATION)

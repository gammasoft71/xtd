cmake_minimum_required(VERSION 3.3)

project(tutorial_application_icon)
find_package(xtd.forms REQUIRED)
add_sources(src/icon.cpp)
target_type(GUI_APPLICATION)

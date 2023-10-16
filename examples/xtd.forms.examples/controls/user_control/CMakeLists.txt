cmake_minimum_required(VERSION 3.20)

project(user_control)
find_package(xtd REQUIRED)
add_sources(README.md src/user_control.cpp)
target_type(GUI_APPLICATION)

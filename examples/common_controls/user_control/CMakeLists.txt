cmake_minimum_required(VERSION 3.3)

project(user_control)
find_package(xtd.forms REQUIRED)
add_sources(src/user_control.cpp)
target_type(GUI_APPLICATION)

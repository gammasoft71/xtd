cmake_minimum_required(VERSION 3.3)

project(choice)
find_package(xtd.forms REQUIRED)
add_sources(src/choice.cpp)
target_type(GUI_APPLICATION)

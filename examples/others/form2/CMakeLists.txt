cmake_minimum_required(VERSION 3.3)

project(form2)
find_package(xtd.forms REQUIRED)
add_sources(src/form2.cpp)
target_type(GUI_APPLICATION)

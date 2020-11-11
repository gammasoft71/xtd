cmake_minimum_required(VERSION 3.3)

project(test_forms)
find_package(xtd.forms REQUIRED)
add_sources(src/test_forms.cpp)
target_type(GUI_APPLICATION)

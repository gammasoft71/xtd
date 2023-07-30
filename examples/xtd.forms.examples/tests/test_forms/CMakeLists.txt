cmake_minimum_required(VERSION 3.5)

project(test_forms)
find_package(xtd REQUIRED)
add_sources(README.md src/test_forms.cpp)
target_type(GUI_APPLICATION)

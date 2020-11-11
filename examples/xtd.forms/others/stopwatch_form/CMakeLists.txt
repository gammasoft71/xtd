cmake_minimum_required(VERSION 3.3)

project(stopwatch_form)
find_package(xtd REQUIRED)
add_sources(src/stopwatch_form.cpp)
target_type(GUI_APPLICATION)

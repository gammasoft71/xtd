cmake_minimum_required(VERSION 3.20)

project(trace_form)
find_package(xtd REQUIRED)
add_sources(src/trace_form.cpp)
target_type(GUI_APPLICATION)

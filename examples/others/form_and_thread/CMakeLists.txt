cmake_minimum_required(VERSION 3.3)

project(form_and_thread)
find_package(xtd.forms REQUIRED)
add_sources(src/form_and_thread.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(form_window_state)
find_package(xtd.forms REQUIRED)
add_sources(src/form_window_state.cpp)
target_type(GUI_APPLICATION)

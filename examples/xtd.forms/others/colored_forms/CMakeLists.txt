cmake_minimum_required(VERSION 3.3)

project(colored_forms)
find_package(xtd REQUIRED)
add_sources(src/colored_forms.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(application_enable_dark_mode)
find_package(xtd REQUIRED)
add_sources(src/application_enable_dark_mode.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.20)

project(application_enable_light_mode)
find_package(xtd REQUIRED)
add_sources(README.md src/application_enable_light_mode.cpp)
target_type(GUI_APPLICATION)

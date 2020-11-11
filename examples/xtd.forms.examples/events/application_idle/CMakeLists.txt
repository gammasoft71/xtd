cmake_minimum_required(VERSION 3.3)

project(application_idle)
find_package(xtd REQUIRED)
add_sources(src/application_idle.cpp)
target_type(GUI_APPLICATION)

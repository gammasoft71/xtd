cmake_minimum_required(VERSION 3.5)

project(application_idle)
find_package(xtd REQUIRED)
add_sources(README.md src/application_idle.cpp)
target_type(GUI_APPLICATION)

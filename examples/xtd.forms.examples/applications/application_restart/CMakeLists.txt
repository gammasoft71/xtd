cmake_minimum_required(VERSION 3.5)

project(application_restart)
find_package(xtd REQUIRED)
add_sources(README.md src/application_restart.cpp)
target_type(GUI_APPLICATION)

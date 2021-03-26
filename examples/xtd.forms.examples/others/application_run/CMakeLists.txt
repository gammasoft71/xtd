cmake_minimum_required(VERSION 3.3)

project(application_run)
find_package(xtd REQUIRED)
add_sources(src/application_run.cpp)
target_type(GUI_APPLICATION)

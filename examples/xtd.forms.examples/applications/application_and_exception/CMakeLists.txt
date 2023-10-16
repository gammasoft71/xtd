cmake_minimum_required(VERSION 3.20)

project(application_and_exception)
find_package(xtd REQUIRED)
add_sources(README.md src/application_and_exception.cpp)
target_type(GUI_APPLICATION)

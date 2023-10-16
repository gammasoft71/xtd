cmake_minimum_required(VERSION 3.20)

project(application)
find_package(xtd REQUIRED)
add_sources(README.md src/application.cpp)
target_type(GUI_APPLICATION)

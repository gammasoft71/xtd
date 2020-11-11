cmake_minimum_required(VERSION 3.3)

project(application)
find_package(xtd REQUIRED)
add_sources(src/application.cpp)
target_type(GUI_APPLICATION)

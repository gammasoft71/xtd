cmake_minimum_required(VERSION 3.20)

project(application_context)
find_package(xtd REQUIRED)
add_sources(README.md src/application_context.cpp)
target_type(GUI_APPLICATION)

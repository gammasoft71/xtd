cmake_minimum_required(VERSION 3.20)

project(application_settings2)
find_package(xtd REQUIRED)
add_sources(README.md src/application_settings2.cpp)
target_type(GUI_APPLICATION)

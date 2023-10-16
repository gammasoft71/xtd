cmake_minimum_required(VERSION 3.20)

project(application_with_cmake_assembly_info)
find_package(xtd REQUIRED)
add_sources(README.md src/application_with_cmake_assembly_info.cpp)
target_type(GUI_APPLICATION)

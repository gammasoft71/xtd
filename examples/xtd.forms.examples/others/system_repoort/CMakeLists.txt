cmake_minimum_required(VERSION 3.3)

project(system_repoort)
find_package(xtd REQUIRED)
add_references(xtd)
add_sources(src/system_repoort.cpp)
target_type(GUI_APPLICATION)

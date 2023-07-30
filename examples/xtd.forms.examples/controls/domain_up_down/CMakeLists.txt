cmake_minimum_required(VERSION 3.5)

project(domain_up_down)
find_package(xtd REQUIRED)
add_sources(README.md src/domain_up_down.cpp)
target_type(GUI_APPLICATION)

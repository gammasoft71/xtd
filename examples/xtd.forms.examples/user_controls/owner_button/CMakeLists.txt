cmake_minimum_required(VERSION 3.3)

project(owner_button)
find_package(xtd REQUIRED)
add_sources(src/owner_button.cpp)
target_type(GUI_APPLICATION)

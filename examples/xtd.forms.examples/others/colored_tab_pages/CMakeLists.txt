cmake_minimum_required(VERSION 3.20)

project(colored_tab_pages)
find_package(xtd REQUIRED)
add_sources(README.md src/colored_tab_pages.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.20)

project(texts)
find_package(xtd REQUIRED)
add_sources(README.md src/texts.cpp)
target_type(GUI_APPLICATION)

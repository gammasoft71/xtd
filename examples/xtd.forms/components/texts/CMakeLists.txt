cmake_minimum_required(VERSION 3.3)

project(texts)
find_package(xtd REQUIRED)
add_sources(src/texts.cpp)
target_type(GUI_APPLICATION)

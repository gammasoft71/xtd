cmake_minimum_required(VERSION 3.20)

project(image)
find_package(xtd REQUIRED)
add_references(xtd.drawing)
add_sources(README.md src/image.cpp src/logo.xpm)
target_type(CONSOLE_APPLICATION)

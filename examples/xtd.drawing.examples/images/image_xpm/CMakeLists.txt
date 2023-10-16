cmake_minimum_required(VERSION 3.20)

project(image_xpm)
find_package(xtd REQUIRED)
add_references(xtd.drawing)
add_sources(README.md src/image_xpm.cpp resources/gammasoft.xpm)
target_type(CONSOLE_APPLICATION)

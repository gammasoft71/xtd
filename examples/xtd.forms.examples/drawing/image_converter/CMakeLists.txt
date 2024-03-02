cmake_minimum_required(VERSION 3.20)

project(image_converter)
find_package(xtd REQUIRED)
target_default_namespace(image_converter_example)
add_sources(README.md src/image_converter.cpp)
target_type(GUI_APPLICATION)

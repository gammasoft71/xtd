cmake_minimum_required(VERSION 3.20)

project(image_transformer)
find_package(xtd REQUIRED)
target_default_namespace(image_transformer_example)
add_sources(README.md src/image_transformer.cpp)
target_type(GUI_APPLICATION)

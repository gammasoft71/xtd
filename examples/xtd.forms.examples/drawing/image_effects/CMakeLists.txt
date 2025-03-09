cmake_minimum_required(VERSION 3.20)

project(image_effects)
find_package(xtd REQUIRED)
target_default_namespace(image_effects_example)
add_sources(README.md src/image_effects.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.20)

project(hello_world_emoticons)
find_package(xtd REQUIRED)
add_sources(README.md src/hello_world_emoticons.cpp)
target_type(GUI_APPLICATION)

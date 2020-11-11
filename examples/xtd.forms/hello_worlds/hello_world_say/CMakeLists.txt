cmake_minimum_required(VERSION 3.3)

project(hello_world_say)
find_package(xtd REQUIRED)
add_sources(src/hello_world_say.cpp)
target_type(GUI_APPLICATION)

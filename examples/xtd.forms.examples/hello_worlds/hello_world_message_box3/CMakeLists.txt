cmake_minimum_required(VERSION 3.3)

project(hello_world_message_box3)
find_package(xtd REQUIRED)
add_sources(src/hello_world_message_box3.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(hello_world_message_box2)
find_package(xtd.forms REQUIRED)
add_sources(src/hello_world_message_box2.cpp)
target_type(GUI_APPLICATION)

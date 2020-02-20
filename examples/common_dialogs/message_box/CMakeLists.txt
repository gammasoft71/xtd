cmake_minimum_required(VERSION 3.3)

project(message_box)
find_package(xtd.forms REQUIRED)
add_sources(src/message_box.cpp)
target_type(GUI_APPLICATION)

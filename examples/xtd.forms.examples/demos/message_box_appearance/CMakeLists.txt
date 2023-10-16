cmake_minimum_required(VERSION 3.20)

project(message_box_appearance)
find_package(xtd REQUIRED)
add_sources(README.md src/message_box_appearance.cpp)
target_type(GUI_APPLICATION)

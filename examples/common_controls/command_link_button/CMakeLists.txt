cmake_minimum_required(VERSION 3.3)

project(command_link_button)
find_package(xtd.forms REQUIRED)
add_sources(src/command_link_button.cpp)
target_type(GUI_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(switch_button)
find_package(xtd.forms REQUIRED)
add_sources(src/switch_button.cpp)
target_type(GUI_APPLICATION)

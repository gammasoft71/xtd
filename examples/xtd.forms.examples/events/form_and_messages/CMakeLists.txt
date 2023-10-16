cmake_minimum_required(VERSION 3.20)

project(form_and_messages)
find_package(xtd REQUIRED)
add_sources(README.md src/form_and_messages.cpp)
target_type(GUI_APPLICATION)

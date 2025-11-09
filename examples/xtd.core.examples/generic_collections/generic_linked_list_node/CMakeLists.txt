cmake_minimum_required(VERSION 3.20)

project(generic_linked_list_node)
find_package(xtd REQUIRED)
add_sources(README.md src/generic_linked_list_node.cpp)
target_type(CONSOLE_APPLICATION)

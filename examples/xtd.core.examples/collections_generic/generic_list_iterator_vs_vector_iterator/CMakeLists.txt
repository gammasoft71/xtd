cmake_minimum_required(VERSION 3.20)

project(generic_list_iterator_vs_vector_iterator)
find_package(xtd REQUIRED)
add_sources(README.md src/generic_list_iterator_vs_vector_iterator.cpp)
target_type(CONSOLE_APPLICATION)

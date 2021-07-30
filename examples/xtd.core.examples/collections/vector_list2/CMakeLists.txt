cmake_minimum_required(VERSION 3.3)

project(vector_list2)
find_package(xtd REQUIRED)
add_sources(src/any_to_ostream.h src/vector_list2.cpp)
target_type(CONSOLE_APPLICATION)

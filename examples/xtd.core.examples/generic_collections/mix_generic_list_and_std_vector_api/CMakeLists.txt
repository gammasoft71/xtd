cmake_minimum_required(VERSION 3.20)

project(mix_generic_list_and_std_vector_api)
find_package(xtd REQUIRED)
add_sources(README.md src/mix_generic_list_and_std_vector_api.cpp)
target_type(CONSOLE_APPLICATION)

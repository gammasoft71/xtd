cmake_minimum_required(VERSION 3.20)

project(class_without_insert_stream_operator)
find_package(xtd REQUIRED)
add_sources(README.md src/class_without_insert_stream_operator.cpp)
target_type(TEST_APPLICATION)

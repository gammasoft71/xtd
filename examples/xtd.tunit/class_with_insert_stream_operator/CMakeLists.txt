cmake_minimum_required(VERSION 3.3)

project(class_with_insert_stream_operator)
find_package(xtd REQUIRED)
add_sources(src/class_with_insert_stream_operator.cpp)
target_type(TEST_APPLICATION)

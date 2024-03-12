cmake_minimum_required(VERSION 3.20)

project(assert_with_message)
find_package(xtd REQUIRED)
add_sources(src/assert_with_message.cpp)
target_type(CONSOLE_APPLICATION)

cmake_minimum_required(VERSION 3.3)

project(delegate_member_method)
find_package(xtd REQUIRED)
add_sources(src/delegate_member_method.cpp)
target_type(CONSOLE_APPLICATION)

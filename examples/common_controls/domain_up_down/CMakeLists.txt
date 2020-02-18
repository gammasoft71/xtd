cmake_minimum_required(VERSION 3.3)

project(domain_up_down)
find_package(xtd.forms REQUIRED)
add_sources(src/domain_up_down.cpp)
target_type(GUI_APPLICATION)
